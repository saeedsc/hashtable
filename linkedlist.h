/*********************
Name: Saeid Jalaliani
Coding 06 COSC 2436
Purpose: This program creates a linked list class and allows adding, traversing,
deleting and retreiving nodes to the caller
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"data.h"
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

class LinkedList{
    
    public:
        
        LinkedList();
        ~LinkedList();
        
        bool addNode(int, string*);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool=false);
        int getCount();
        bool clearList();
        bool exists(int);
    
    private:
        Node* head;
        void addHead(Node*, int, string*);
        void addTail(Node*, Node* ,int, string*);
        void addMiddle(Node*,Node*, int, string*);
        
};
#endif //LINKEDLIST_H