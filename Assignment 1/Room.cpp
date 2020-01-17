#include <string>

#include "DateHandler.h"
#include "Room.h"

using namespace std;

Room::Room(string customer, DateHandler checkIn, DateHandler checkOut, int numberOfBed) {
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->customer = customer;
    this->numberOfBed = numberOfBed;
}

Room::Room(int numberOfBed) {
    this->numberOfBed = numberOfBed;
    this->customer = "";
    this->checkIn = DateHandler();
    this->checkOut = DateHandler();
}