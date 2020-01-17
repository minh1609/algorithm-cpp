#ifndef ROOMLINKEDLIST_H
#define ROOMLINKEDLIST_H

#include "Room.h"

using namespace std;

//Each node hold 1 room
struct node {
    Room room = Room(0);
    node* next;
};

class RoomLinkedList {
   private:
    node *head, *tail;

   public:
    RoomLinkedList();

    //display room list to screen
    void print();
    //add Room to Linked List
    void addRoom(Room newRoom);
};

#endif