const s = (p) => {
  function niceAngle(angle) {
    while (angle < 0)
      angle += p.TWO_PI;

    return angle;
  }

  class Cell {
    //Every cell that gets placed gets a new ID
    //This method ensures that the IDs are created statically and always valid
    static getNextID() {
      this.nextID++;
      return this.nextID;
    }

    //(x1, y1) and (x2, y2) represent the base of the cell's shape
    //Two points of the three needed for a triangle
    constructor(x1, y1, x2, y2, parent) {
      //Map (x2, y2) to (x3, y3) just because of how triangles are drawn
      this.x1 = x1;
      this.x3 = x2;
      this.y1 = y1;
      this.y3 = y2;

      //Create an invalid ID
      this.ID = -1;
      this.parent = parent;

      //These counters are used to prevent recursion loops when a cell connects back to itself
      //These counts are updated by the base methods update, draw, and place
      //If the cell's count already matches the supplied count, then the call returns immediately
      this.updateCount = -1;
      this.drawCount = -1;
      this.placeCount = -1;

      //Calculate the base length and angle
      this.base = p.dist(x1, y1, x2, y2);
      this.angle = p.atan2(y1 - y2, x2 - x1);

      //So that the missing point can be calculated
      //Equilateral triangles are 60° so PI/3 radians
      this.x2 = this.x1 + (this.base * p.cos(this.angle + (p.PI / 3)));
      this.y2 = this.y1 - (this.base * p.sin(this.angle + (p.PI / 3)));

      //Calculate the center position to determine when the mouse is inside of the cell
      this.centerX = (this.x1 + this.x2 + this.x3) / 3;
      this.centerY = (this.y1 + this.y2 + this.y3) / 3;

      //Some flags
      this.bPlaced = false; //Placed indicates that the cell is always shown and it's children have been created
      this.bInCell = false;

      //The child cells, null at start and created when placed
      this.leftChild = null;
      this.rightChild = null;
    }

    update(x, y, updateCount) {
      if (this.updateCount == updateCount)
        return;

      this.updateCount = updateCount;

      if (p.dist(x, y, this.centerX, this.centerY) < (this.base / 4)) {
        this.bInCell = true;
      } else {
        this.bInCell = false;

        if (this.leftChild != null)
          this.leftChild.update(x, y, updateCount);

        if (this.rightChild != null)
          this.rightChild.update(x, y, updateCount);
      }
    }

    draw(drawCount) {
      if (this.drawCount == drawCount)
        return;

      this.drawCount = drawCount;

      if (this.bPlaced || this.bInCell)
        p.triangle(this.x1, this.y1, this.x2, this.y2, this.x3, this.y3);

      //If the cell has been placed, recursively update the child cells
      if (this.bPlaced) {
        if (this.leftChild != null)
          this.leftChild.draw(drawCount);

        if (this.rightChild != null)
          this.rightChild.draw(drawCount);
      }
    }

    place(pCell, placeCount) {
      if (this.placeCount == placeCount)
        return;

      this.placeCount = placeCount;

      //Has this cell already been placed?
      if (this.bInCell) {
        if ( /*this.bPlaced*/ false) //Disable cell delete function
          this.bPlaced = false;
        else if (!this.bPlaced) {
          //Has a cell already been created?
          //This should only happen when 2 cells happen to overlap
          if (pCell == null) { //If no other cell has been created
            //Just proceed as usual
            this.bPlaced = true; //Set the placed flag
            this.ID = Cell.getNextID(); //Get the next ID

            if (this.parent != null) {
              if (this == this.parent.leftChild)
                p.print("Placing", this.ID, "left child of", this.parent.ID);
              else if (this == this.parent.rightChild)
                p.print("Placing", this.ID, "right child of", this.parent.ID);
            } else
              p.print("Placing", this.ID);

            //Create the children cells
            this.leftChild = new Cell(this.x1, this.y1, this.x2, this.y2, this);
            this.rightChild = new Cell(this.x2, this.y2, this.x3, this.y3, this);

            //Return the newly placed cell reference
            return this;
          } else { //Another cell has already been created
            //Figure out which cells need to be deleted
            //Calculate the relative angle that points from one cell to the next
            //This is the angle from the current cell's parent to the cell that was already created
            let parent2CellAngle = p.atan2(this.parent.centerY - pCell.centerY, pCell.centerX - this.parent.centerX) - this.parent.angle;
            //This is the angle from the created cell to the current cell's parent
            let cell2ParentAngle = p.atan2(pCell.centerY - this.parent.centerY, this.parent.centerX - pCell.centerX) - pCell.angle;
            //These two angles are then offset by the base angle of the respective cell
            //This translates the angle to point out one of the two "out" directions

            //Convert the angle to be between 0 and PI
            parent2CellAngle = niceAngle(parent2CellAngle);
            cell2ParentAngle = niceAngle(cell2ParentAngle);

            p.print(cell2ParentAngle, parent2CellAngle);

            //Angles past PI/2 mean the connection is out the left
            if (cell2ParentAngle > p.HALF_PI) {
              p.print("Removing left child of cell");
              pCell.leftChild = this.parent;
            } else {
              p.print("Removing right child of cell");
              pCell.rightChild = this.parent;
            }

            if (parent2CellAngle > p.HALF_PI) {
              p.print("Removing left child of parent");
              this.parent.leftChild = pCell;
            } else {
              p.print("Removing right child of parent");
              this.parent.rightChild = pCell;
            }
          }
        }
      } else if (this.bPlaced) {
        //This cell has already been placed? Check its children
        //Handle each case so that the overlap is done correctly with recursion
        if (this.leftChild != null && this.rightChild != null) //Hard
          return this.leftChild.place(this.rightChild.place(pCell, placeCount), placeCount);
        else if (this.leftChild != null) //Easy
          return this.leftChild.place(pCell, placeCount);
        else if (this.rightChild != null) //Easy
          return this.rightChild.place(pCell, placeCount);
      }

      return pCell;
    }
  };
  Cell.nextID = 0; //Initialize the base ID to 0. Each cell after starts at 1,2,3,...

  class Base {
    constructor() {
      this.x = this.y = 0;
      this.angle = 0;

      this.drawCount = 0;
      this.updateCount = 0;
      this.placeCount = 0;

      this.bPlaced = false;
      this.child = null;
    }

    update(x, y) {
      if (!this.bPlaced) {
        this.x = x;
        this.y = y;
      } else
        this.child.update(x, y, this.updateCount);

      this.updateCount++;
    }

    draw() {
      p.quad(this.x - 20, this.y - 10, this.x + 20, this.y - 10, this.x + 10, this.y + 10, this.x - 10, this.y + 10);

      //Recursively update the child cells
      if (this.bPlaced)
        this.child.draw(this.drawCount);

      this.drawCount++;
    }

    place() {
      if (!this.bPlaced) {
        this.bPlaced = true;
        this.child = new Cell(this.x - 20, this.y - 10, this.x + 20, this.y - 10);
      } else
        this.child.place(null, this.placeCount);

      this.placeCount++;
    }
  };

  p.setup = function() {
    p.createCanvas(p.windowWidth / 2, p.windowHeight / 2);
  }

  let b = new Base();

  p.draw = function() {
    p.background(64);

    //All updates are done recursively
    b.update(p.mouseX, p.mouseY);
    //All draws are done recursively
    b.draw();
  }

  p.mouseClicked = function() {
    //Bounds check, make sure nothing is drawn off screen
    if (p.mouseX >= 0 && p.mouseX < p.width && p.mouseY >= 0 && p.mouseY < p.height)
      //All places are done recursively
      b.place();
  }

  p.windowResized = function() {
    p.resizeCanvas(p.windowWidth / 2, p.windowHeight / 2);
  }
};

let myp5 = new p5(s);