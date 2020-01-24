#include "RoomLinkedList.h"
#include "Room.h"

#include <iostream>

using namespace std;

RoomLinkedList::RoomLinkedList(int max) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    maxSize = max;
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
    size++;
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

int RoomLinkedList::getSize() {
    return size;
}

void RoomLinkedList::remove(node* n) {
    if (size == 0 || size == 1) {
        return;
    }
    if (head == n) {
        head->room = head->next->room;
        n = head->next;
        head->next = head->next->next;
        delete n;
        return;
    } else {
        node* before = head;
        while (before->next != nullptr && before->next != n) {
            before = before->next;
        }
        if (before->next == nullptr) {
            return;
        }
        before->next = before->next->next;
        delete n;
    }
}

void RoomLinkedList::removeUnusedRoom(DateHandler today) {
    node* tmp = new node;
    tmp = head;
    while (tmp != nullptr) {
        if (tmp->room.checkOut.isSmallerOrEqual(today)) {
            //remove that node
            node* next = tmp->next;
            remove(tmp);
            size--;
            tmp = next;
        } else {
            tmp = tmp->next;
        }
    }
}

int RoomLinkedList::available() {
    return maxSize - size;
}
