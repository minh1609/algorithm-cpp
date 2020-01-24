#ifndef ROOMLINKEDLIST_H
#define ROOMLINKEDLIST_H

#include "DateHandler.h"
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
    int size;
    int maxSize;

   public:
    RoomLinkedList(int maxSize);
    int getSize();

    //display room list to screen
    void print();
    //add Room to Linked List
    void addRoom(Room newRoom);
    //remove node
    void remove(node* node);
    //remove unused room from list (room has checkout date <= today)
    void removeUnusedRoom(DateHandler today);
    //return available room
    int available();
};

#endif