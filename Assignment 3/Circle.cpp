// Description: This class models a Circle
// Author: Minh Nguyen
// Creation date: Jan 10

#include "Circle.h"
#include <math.h>
#include <iostream>
using namespace std;

Circle::Circle() {
    x = 0;
    y = 0;
    radius = 10;
    count++;
}

Circle::Circle(int x, int y, double radius) {
    this->setRadius(radius);
    this->x = x;
    this->y = y;
    count++;

    if (this->onLeftSide()) {
        countLeft++;
    }
}

int Circle::getX() {
    return x;
}

int Circle::getY() {
    return y;
}

double Circle::getRadius() {
    return radius;
}

void Circle::translateXY(int x, int y) {
    bool alreadyOnLeftSide = this->onLeftSide();

    this->x = x;
    this->y = y;

    if (this->onLeftSide() && alreadyOnLeftSide) {
        //do nothing
    } else if (this->onLeftSide() && !alreadyOnLeftSide) {  //circle move to left side after translate
        countLeft++;
    } else if (!this->onLeftSide() && !alreadyOnLeftSide) {
        //do nothing
    } else if (!this->onLeftSide() && alreadyOnLeftSide) {  //circle move to right side or intersect with Oy after translate
        countLeft--;
    }
}

void Circle::setRadius(double r) {
    bool alreadyOnLeftSide = this->onLeftSide();

    if (r <= 0) {
        this->radius = 10;
    } else {
        this->radius = r;
    }

    if (this->onLeftSide() && alreadyOnLeftSide) {
        //do nothing
    } else if (this->onLeftSide() && !alreadyOnLeftSide) {  //circle move to left side after translate
        countLeft++;
    } else if (!this->onLeftSide() && !alreadyOnLeftSide) {
        //do nothing
    } else if (!this->onLeftSide() && alreadyOnLeftSide) {  //circle move to right side or intersect with Oy after translate
        countLeft--;
    }
}

void Circle::displayCircle() {
    cout << "[x=" << this->x << ", y=" << this->y << ", radius=" << this->radius << "]" << endl;
}

double Circle::computeArea() {
    return 3.14 * radius * radius;
}

bool Circle::intersect(Circle c2) {
    double distance = sqrt(pow(x - c2.getX(), 2) + pow(y - c2.getY(), 2));
    if (distance <= this->radius + c2.getRadius()) {
        return true;
    } else {
        return false;
    }
}

int Circle::getNumberOfCurrentCircles() {
    return count;
}

bool Circle::onLeftSide() {
    if (x >= 0) {
        return false;
    }

    if (abs(x) > radius) {
        return true;
    }

    return false;
}

int Circle::getNumberOfCircleOnLeftSide() {
    return countLeft;
}

int Circle::count = 0;
int Circle::countLeft = 0;
