#include <iostream>  // As we need to print data
#include "Circle.cpp"

using namespace std;

int main() {
    cout << std::boolalpha;  //print true false instead of 0 1 for bool

    Circle c1 = Circle();
    Circle c2 = Circle(1, 1, -2);    //c2 with radius < 0
    Circle c3 = Circle(-10, -4, 1);  //c3 in left side of y-axis

    //PRINT CIRCLE
    cout << "print c1 ";
    c1.displayCircle();

    cout << "print c2 ";
    c2.displayCircle();

    cout << "print c3 ";
    c3.displayCircle();

    cout
        << "Number of circle: " << Circle::getNumberOfCurrentCircles() << endl;

    cout << "c1 intersect with c2: " << c1.intersect(c2) << endl;

    cout << "c3 on left side of y-axis: " << c3.onLeftSide() << endl;

    cout
        << "BONUS: Circle on left side: " << Circle::getNumberOfCircleOnLeftSide() << endl;

    c3.translateXY(2, 1);

    cout << "Circle on left side after c3 transform to (2,1): " << Circle::getNumberOfCircleOnLeftSide() << endl;
    return 0;
}