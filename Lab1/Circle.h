
// Description: This class models a Circle
// Author: Minh Nguyen
// Creation date: Jan 10
class Circle {
   private:
    int x;
    int y;
    double radius;
    static int count;
    static int countLeft;

   public:  //everything that follows is public
    //Default constructor
    Circle();
    // Constructor to create a new circle with the given values
    Circle(int x, int y, double radius);

    //GETTER
    int getX();
    int getY();
    double getRadius();

    //SETTER
    //Updates the x and y coordinate of the circle that is added to this X and Y, respectively.
    void translateXY(int x, int y);
    void setRadius(double r);

    //computes and returns the circle's area
    double computeArea();
    //displays the circle's attributes
    void displayCircle();
    //returns true if c2 intersects with the current circle
    bool intersect(Circle c2);
    //count all the objects that exist in the program
    static int getNumberOfCurrentCircles();

    //count all circles on left side of y-axis
    static int getNumberOfCircleOnLeftSide();

    //return true if circle on left side of y-axis
    bool onLeftSide();
};
