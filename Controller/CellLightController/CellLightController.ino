#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <FS.h>
#include <LittleFS.h>

#include "Msgs.h"

#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

ESP8266WebServer server(80);

void handleRoot()
{
  server.sendHeader("Location", "/index.html", true);
  server.send(302);
}

void handleCellConfigRequest()
{
  Serial.print("POST:");
  Serial.println(server.arg("plain"));

  server.send(200);
}

void handleWifiListReq()
{
  int nScanStatus = WiFi.scanComplete();
}

void setup()
{
  delay(3000);
  Serial.begin(115200);
  Serial.flush();

  Serial1.begin(115200);
  Serial1.flush();

  Serial.print("Mounting file system...");
  if (!LittleFS.begin())
  {
    Serial.println("failed");
    while (1);
  }
  Serial.println("success");

  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin("KaddyWompus", "jose5598dan6056ate");
  for (int i = 0; (i < 20) && (WiFi.status() != WL_CONNECTED); i++)
  {
    Serial.print('.');
    delay(500);
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("failed");
    while (1);
  }
  Serial.println("success");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Starting mDNS...");
  if (!MDNS.begin("esp8266"))
  {
    Serial.println("failed");
    while (1);
  }
  Serial.println("success");

  server.on("/", HTTP_GET, handleRoot);

  //Serve webpages from file system
  server.serveStatic("/", LittleFS, "/");
  server.enableETag(true);

  server.on("/lightconfig", HTTP_POST, handleCellConfigRequest);
  server.on("/lightcontrol", HTTP_POST, NULL);
  server.on("/wifi", HTTP_GET, handleWifiListReq);

  Serial.print("Starting server...");
  server.begin();
  Serial.println("success");

  MDNS.addService("http", "tcp", 80);
}

void SendSerialMsg(uint16_t msgType, void* pBuffer, uint8_t msgLen)
{

}

#define MAX_CELL_SIDES  3
#define MAX_TOTAL_CELLS 256

uint16_t nMaxCellID = 0;
uint8_t CellConnections[MAX_TOTAL_CELLS][MAX_CELL_SIDES] = {0};

enum
{
  ADDRESS_CELL = 0,
  SET_OUTPUT,
  SET_INPUT,
  ALL_CELL_CONFIG_STAGE
} CELL_CONFIG_STAGE;

bool ConfigureCells(uint16_t* pCellIndex, uint8_t* pSideIndex, uint8_t* pConfigStage)
{
  bool bIncrement = false;

  DEBUG_MSG("%s Cell %d Side %d Stage %d\n", __FUNCTION__, (*pCellIndex), (*pSideIndex), (*pConfigStage));

  if ((*pCellIndex) > nMaxCellID)
    return true;

  switch (*pConfigStage)
  {
    //Address the cell
    case ADDRESS_CELL:
      {
        if (CellConnections[(*pCellIndex)][(*pSideIndex)] != 0)
        { 
          ADDRESS_CELL_MSG_t msg;
          msg.address = CellConnections[(*pCellIndex)][(*pSideIndex)];
          DEBUG_MSG("Address cell %d\n", msg.address);

          SendSerialMsg(ADDRESS_CELL_MSG, &msg, sizeof(ADDRESS_CELL_MSG_t));
          (*pConfigStage) = SET_OUTPUT;
        }
        bIncrement = true;
      }
      break;

    //Set the next port as an output
    case SET_OUTPUT:
      {
        if (CellConnections[(*pCellIndex)][(*pSideIndex)] != 0)
        {
          CONFIGURE_PORT_MSG_t msg;
          msg.offset = (*pSideIndex);
          msg.portStatus = PORT_OUTPUT;
          DEBUG_MSG("Set port %d cell %d as output\n", msg.offset, (*pCellIndex));

          SendSerialMsg(CONFIGURE_PORT_MSG, &msg, sizeof(CONFIGURE_PORT_MSG_t));
        }

        (*pConfigStage) = ADDRESS_CELL;
      }
      break;

    case SET_INPUT:
      {
        CONFIGURE_PORT_MSG_t msg;
        msg.offset = (*pSideIndex);
        msg.portStatus = PORT_INPUT;

        SendSerialMsg(CONFIGURE_PORT_MSG, &msg, sizeof(CONFIGURE_PORT_MSG_t));
        (*pConfigStage) = SET_OUTPUT;
      }
      break;
  }

  if (bIncrement)
  {
    (*pSideIndex)++;
    if ((*pSideIndex) >= MAX_CELL_SIDES)
    {
      (*pSideIndex) = 0;
      (*pCellIndex)++;
      (*pConfigStage) = SET_INPUT;
    }
  }

  return false;
}

bool bCellsConfigured = false;

void loop()
{
  MDNS.update();
  server.handleClient();

  if (!bCellsConfigured && ConfigureCells(NULL, NULL, NULL))
    bCellsConfigured = true;
}
