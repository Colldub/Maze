/*
    Computer Science 2
    Queues Implementation File

    Collin Worth 10-24-2023
*/

#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(){
    head = NULL;
}
Queue::~Queue(){

}

// Takes a double and puts it at the end of the queue
void Queue::enqueue(double d){
    
    Node* n = new Node;
    n->next = NULL;
    n->data = d;

    if(head == NULL){
        head = n;
    }else{

        Node* tmp = head;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = n;
    }
}

// "pops" the front of the queue and deletes it
double Queue::dequeue(){
    if(head == NULL){
        return 0;
    }

    double ret = head->data;
    Node* temp = head; // Store the pointer to the node being removed
    head = head->next;
    delete temp; // Deallocate memory for the removed node

    return ret;
}

// Returns the current front head
double Queue::peek(){
    double ret = 0;
    if(head != NULL){
        ret = head->data;
    }
    return ret;
}

// Prints out the Queue
void Queue::print(){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

// Deletes the entire Queue
void Queue::Delete(){
    while(head != NULL){
        Node* tmp = new Node;
        tmp = head;
        head = head->next;
        delete tmp;
    }
    delete head;
}