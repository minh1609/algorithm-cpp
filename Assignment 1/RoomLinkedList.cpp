#include "RoomLinkedList.h"
#include "Room.h"

#include <iostream>

using namespace std;

RoomLinkedList::RoomLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void RoomLinkedList::addRoom(Room newRoom) {
    node* temp = new node;
    temp->room = newRoom;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp = nullptr;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void RoomLinkedList::print() {
    node* temp = new node;
    temp = head;
    while (temp != nullptr) {
        if (temp->room.customer.length() == 0) {
            cout << "EMPTY" << endl;
            temp = temp->next;
        } else {
            cout << temp->room.customer << "||";
            temp->room.checkOut.print();
            cout << endl;
            temp = temp->next;
        }
    }
}
