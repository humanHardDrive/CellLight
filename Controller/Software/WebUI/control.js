const s = (p) => {
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

      //Calculate the base length and angle
      this.base = p.dist(x1, y1, x2, y2);
      this.angle = p.atan2(y1 - y2, x2 - x1) + (p.PI / 3); //Equilateral triangles are 60° so PI/3 radians

      //So that the missing point can be calculated
      this.x2 = this.x1 + (this.base * p.cos(this.angle));
      this.y2 = this.y1 - (this.base * p.sin(this.angle));

      //Calculate the center position to determine when the mouse is inside of the cell
      this.centerX = (this.x1 + this.x2 + this.x3) / 3;
      this.centerY = (this.y1 + this.y2 + this.y3) / 3;

      //Some flags
      this.bPlaced = false; //Placed indicates that the cell is always shown and it's children have been created
      this.bCanDraw = false; //Draw just means that the cell should be shown whether or not it's been placed

      //The child cells, null at start and created when placed
      this.leftChild = null;
      this.rightChild = null;
    }

    update(x, y) {
      if (!this.bPlaced) { //Update the bCanDraw flag when the mouse is in the cell
        if (p.dist(x, y, this.centerX, this.centerY) < (this.base / 4)) //Div by 4 so that 2 cells aren't active at the same time
          this.bCanDraw = true;
        else
          this.bCanDraw = false;
      } else { //Recursively update the child cells
        if (this.leftChild != null)
          this.leftChild.update(x, y);

        if (this.rightChild != null)
          this.rightChild.update(x, y);
      }
    }

    draw() {
      //Draw the cell. This should work out so that once the cell is placed, this flag is always true
      if (this.bCanDraw)
        p.triangle(this.x1, this.y1, this.x2, this.y2, this.x3, this.y3);

      //If the cell has been placed, recursively update the child cells
      if (this.bPlaced) {
        if (this.leftChild != null)
          this.leftChild.draw();

        if (this.rightChild != null)
          this.rightChild.draw();
      }
    }

    place(pCell) {
      //Has this cell already been placed?
      //Using the bCanDraw flag is nice because it means that the mouse is already in the cell
      if (!this.bPlaced && this.bCanDraw) {
        //Has a cell already been created?
        //This should only happen when 2 cells happen to overlap
        if (pCell == null) { //If no other cell has been created
          //Just proceed as usual
          this.bPlaced = true; //Set the placed flag
          this.ID = Cell.getNextID(); //Get the next ID

          //Create the children cells
          this.leftChild = new Cell(this.x1, this.y1, this.x2, this.y2, this);
          this.rightChild = new Cell(this.x2, this.y2, this.x3, this.y3, this);

          //Return the newly placed cell reference
          return this;
        } else { //Another cell has already been created
          //Find out which child this is (left/right)
          if (this == this.parent.leftChild) {
            this.parent.leftChild = null; //Nullify the parent's child reference so the cell isn't updated and can't be placed in future
            //This should be symmetrical where the parent and the other created cell's right child are the same. So nullify that one as well so more cells don't overlap
            pCell.rightChild = null;
          } else if (this == this.parent.rightChild) { //Same goes for the right child
            this.parent.rightChild = null;
            pCell.leftChild = null;
          } else //Catchall. Don't know when this would happen
            p.print("WHAT");
        }
      } else if (this.bPlaced) {
        //This cell has already been placed? Check its children
        //Handle each case so that the overlap is done correctly with recursion
        if (this.leftChild != null && this.rightChild != null) //Hard
          return this.leftChild.place(this.rightChild.place(pCell));
        else if (this.leftChild != null) //Easy
          return this.leftChild.place(pCell);
        else //Easy
          return this.rightChild.place(pCell);
      }

      return pCell;
    }
  };
  Cell.nextID = 0; //Initialize the base ID to 0. Each cell after starts at 1,2,3,...

  class Base {
    constructor() {
      this.x = this.y = 0;
      this.angle = 0;

      this.bPlaced = false;
      this.child = null;
    }

    update(x, y) {
      if (!this.bPlaced) {
        this.x = x;
        this.y = y;
      } else {
        this.child.update(x, y);
      }
    }

    draw() {
      p.quad(this.x - 20, this.y - 10, this.x + 20, this.y - 10, this.x + 10, this.y + 10, this.x - 10, this.y + 10);

      //Recursively update the child cells
      if (this.bPlaced)
        this.child.draw();
    }

    place() {
      if (!this.bPlaced) {
        this.bPlaced = true;
        this.child = new Cell(this.x - 20, this.y - 10, this.x + 20, this.y - 10);
      } else {
        this.child.place(null);
      }
    }
  };

  p.setup = function() {
    p.createCanvas(p.windowWidth, p.windowHeight);
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
    if(p.mouseX >= 0 && p.mouseX < p.width && p.mouseY >= 0 && p.mouseY < p.height)
        b.place();
  }
  
  p.windowResized = function() {
	p.resizeCanvas(p.windowWidth, p.windowHeight);
  }
};

let myp5 = new p5(s);
