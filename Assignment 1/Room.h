#ifndef ROOM_H
#define ROOM_H

#include <ctime>
#include <string>

#include "DateHandler.h"

using namespace std;

class Room {
   public:
    string customer;  //empty string ==> room is available
    DateHandler checkIn;
    DateHandler checkOut;  //check out date <= current date ==> room is available
    int numberOfBed;

    //Constructor
    Room(int numberOfBed);
    Room(string customer, DateHandler checkIn, DateHandler checkOut, int numberOfBed);
};

#endif