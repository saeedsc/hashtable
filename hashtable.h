/*********************
Name: Saeid Jalaliani
Coding 07 COSC 2436
Purpose: This program creates a hashtable using seperate chaining and linked list from previous assignment
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedlist.h"
#define HASHTABLESIZE 15


class Hashtable: public LinkedList{
	public:
		Hashtable();
		~Hashtable();
		
		bool insertEntry(int, string);
		string getData(int);
		bool removeEntry(int);
		int getCount();
		void printTable();
	
	private:
		int hash(int);
        int count;
        LinkedList hashTable[HASHTABLESIZE]; //array of linked list objects
};

#endif //HASHTABLE