/*********************
Name: Saeid Jalaliani
Coding 06 COSC 2436
Purpose: This program creates a linked list class and allows adding, traversing,
deleting and retreiving nodes to the caller
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();                      
}

bool LinkedList::addNode(int num, string *temp){
    
    Node* current = head;
    
    bool success = false;
    bool whileCheck = false;
    
    if(num > 0 && *temp!=""){
        
        while((current || !head) && !whileCheck){ //while current is pointing to something or head is NULL and loop check is false
            if(head == NULL){
                Node* newNode= new Node;
                
                head = newNode;
                newNode->data.id = num;
                newNode->data.data = *temp;
                
                newNode->prev = NULL;
                newNode->next = NULL;
                
                whileCheck = true;
                success = true;
                
            } else if (num < head->data.id) {
                Node* newNode = new Node;
                addHead(newNode, num, temp);
                
                whileCheck = true;
                success = true;
            } else if (num == current->data.id){
                whileCheck = true;
                success = false;
            } else if (num > current->data.id && current->next == NULL){ //condition checks current->next to ensure it is not NUll before continuing, to avoid falling off for tail case
                Node* newNode = new Node;
                addTail(newNode, current, num, temp);
                
                whileCheck = true;
                success=true;
            } else if ((num < current->data.id) && (num > current->prev->data.id)) {
                Node* newNode = new Node;
                addMiddle(newNode, current, num, temp);
                
                whileCheck=true;
                success = true;
            } else {
                current = current->next;
            }
        }
        
    } else {
        success = false;
    }
    
    return success;
}

bool LinkedList::deleteNode(int num){
    Node* current = head;
    bool erased = false;
    
    while(current && !erased){
    
    if(num == current->data.id && current->next == NULL && current->prev == NULL){
    
       delete current;
       head = NULL;
       
       erased = true;    
    
    }else if(num == head->data.id){
        head = head->next;
        head->prev=NULL;
        delete current;
        current = head;
        
        erased = true;
    } else if ((num == current->data.id) && current->next==NULL){
        
        current->prev->next = NULL;
        
        delete current;
        
        erased = true;
        
    } else if (num == current->data.id){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        delete current;
        
        erased = true;
    } else {
        current = current->next;
    }
    
}

return erased;
}

bool LinkedList::getNode(int num, Data *temp){
    
    Node* current = head;
    bool found = false;
    
    while(!found && current){
        
        if(num == current->data.id){
            temp->data = current->data.data;
            temp->id = current->data.id;
            
            found = true;
        } else {
            
            temp->data = "";
            temp->id = -1;
            current = current->next;
        }
    }
    
    return found;
}

void LinkedList::printList(bool backwards){
   
   if(head!=NULL && backwards){
        Node *current = head;
        bool tail = false;
        while(current && !tail){
            if(current->next){
                current = current->next;
            } else {
                tail = true;
            }
        }
        
        while(current){
            cout << current->data.id << "--> ";
            current = current->prev;
        }
    } else if(head!=NULL && !backwards){
        Node *current = head;
        while(current){
            cout << current->data.id << "--> ";
            current = current->next;
        }
        cout << endl;
    } 
}

int LinkedList::getCount(){

    int count=0;
    Node* current = head;
    
    while(current){
        current=current->next;
        count++;
    }

    return count;
}

bool LinkedList::clearList(){
    
    Node* current = head;
    bool erased = false;
    
    while(current !=NULL){
        head = current->next;
        delete current;
        current = head;
        erased = true;
    }
    

    return erased;
}

bool LinkedList::exists(int id){
    
    Node* current = head;
    bool found = false;
    
    while(current && !found){
        if(id == current->data.id){
            found = true;
        } else {
            current = current->next;
        }
    }
    
    return found;
}

void LinkedList::addHead(Node* newNode, int num, string *temp){
    
    newNode->data.id = num;
    newNode->data.data = *temp;
    
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
}

void LinkedList::addTail(Node* newNode, Node* current, int num, string *temp){
    newNode->data.id = num;
    newNode->data.data = *temp;
    
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
}

void LinkedList::addMiddle(Node* newNode, Node* current, int num, string *temp){
    newNode->data.id = num;
    newNode->data.data = *temp;
    
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;   
}