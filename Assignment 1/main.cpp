#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "DateHandler.cpp"
#include "Room.cpp"
#include "RoomLinkedList.cpp"
using namespace std;

int main() {
    // DateHandler t1 = DateHandler(1, 1, 2014);
    // t1.addDay(5);
    // cerr << t1.getDay() << " " << t1.getMonth() << " " << t1.getYear();

    // DateHandler checkIn = DateHandler(1, 1, 2020);
    // DateHandler checkOut = DateHandler(2, 1, 2020);
    // Room myRoom = Room("46842354", checkIn, checkOut, 2);
    // cerr << myRoom.customer;

    RoomLinkedList beds = RoomLinkedList();
    beds.addRoom(1);
    beds.addRoom(2);
    beds.addRoom(2);
    beds.print();

    return 0;
}