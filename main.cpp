/*********************
Name: Saeid Jalaliani
Coding 07 COSC 2436
Purpose: This program creates a hashtable using seperate chaining and linked list from previous assignment
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable table1;
    // show it is empty by calling getCount and printTable
    cout << "Begin. Table should be empty and count should be 0 at this point." << endl << endl;
    cout << "Count: " << table1.getCount() << endl;
    table1.printTable();
    
    // try and put ALL the test data into the table and show what happens
    bool success=false;
    int invalid = 0;
    
    for(int i=0;i<testdatasize;i++){
    	success=table1.insertEntry(ids[i],strs[i]);
    	if(!success){
    		cout << "Entry number " << i+1 <<" was invalid." << endl;
    		invalid++;
		}
	}
	cout << "===================" << endl << endl;
	cout << "Count: " << table1.getCount()+invalid << ", " << invalid <<" data was not inserted."<<endl;
    table1.printTable();
    
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
   	//randomly deleting some data
	cout << "Deleting some enteries and printing again: " << endl << endl;
	int random = 0;
	random = rand() % ((testdatasize/2)+1);
    
    for(int i=0;i<random;i++){
    	table1.removeEntry(ids[i]);
	}
	
	cout << "Count: " << table1.getCount() << endl;
    table1.printTable();
	
	//add a random amount of data on top of existing table
	
	const int testdatasize2 = BASE + (rand() % (OFFSET/5) + 1);
    invalid = 0;
    
    for (int i = 0; i < testdatasize2; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
 
    
    for(int i=0;i<testdatasize2;i++){
    	success=table1.insertEntry(ids[i],strs[i]);
    	if(!success){
    		cout << "Entry number " << i+1 <<" was invalid." << endl;
    		invalid++;
		}
	}
	cout << endl << "======== added "<<testdatasize2<< " more data to the existing table =========" << endl << endl;
	cout << "Count: " << table1.getCount()+invalid << ", " << invalid <<" data was not inserted."<<endl;
    table1.printTable();
    
    //add some more invalid data
   
    const int testdatasize3 = BASE + (rand()%(testdatasize/4)+1);
    
    int badIds[testdatasize3];
    string badStrs[testdatasize3];
    
        for (int i = 0; i < testdatasize3; i++) {
        badIds[i] = (-20)-i;
        badStrs[i] = "bad data";
    }
    
    cout << "Now trying to insert " << testdatasize3 << " invalid data: " << endl << endl;
        for(int i=0;i<testdatasize3;i++){
    	success=table1.insertEntry(badIds[i],badStrs[i]);
    	if(!success){
    		cout << "Entry number " << i+1 <<" was invalid." << endl;
    		invalid++;
		}else{
			cout << "Entry inserted." << endl;
		}
	} 
    
    
    
    return 0;
}
