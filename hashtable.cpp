/*********************
Name: Saeid Jalaliani
Coding 07 COSC 2436
Purpose: This program creates a hashtable using seperate chaining and linked list from previous assignment
**********************/

#include "hashtable.h"

Hashtable::Hashtable(){
    count = 0;
}

Hashtable::~Hashtable(){
  /*  for(int i=0; i<HASHTABLESIZE;i++){
        hashTable[i].clearList();
    } */
}

bool Hashtable::insertEntry(int id, string info){
    bool success = false;
    int index;
    index = hash(id);
    
    success = hashTable[index].addNode(id, &info);
    
    if(success){
        count++;
    }
    
    return success;
}

string Hashtable::getData(int id){
    
    string localStr;
    bool retrieved = false;
    int index;
    Data temp;
    
    retrieved = hashTable[index].getNode(index, &temp);
    
    if(retrieved){
        localStr = temp.data;
    } else {
        localStr = "Empty";
    }
    
    return localStr;
}

bool Hashtable::removeEntry(int id){
    
    bool removed = false;
    int index;
    index = hash(id);
    
    removed = hashTable[index].deleteNode(id);
    
    if(removed){
        count--;
    }
    
    return removed;
}


int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    cout << "Printing table: " << endl << endl;
    
    for(int i=0; i<HASHTABLESIZE; i++){
        if (count == 0){
            cout << "Entry " << i+1 << ": Empty" << endl;
        } else if(hashTable[i].getCount()==0) {
            cout << "Entry " << i+1 << ": Empty" << endl;
        } else {
            cout << "Entry " << i+1 << ": ";
            hashTable[i].printList(false);
        }
    }
}

int Hashtable::hash(int id){
    return id %HASHTABLESIZE;
}