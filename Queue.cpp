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

double Queue::dequeue(){
    double ret = 0;

    if(head == NULL){
        ret = 0;
    }else{
        ret = head->data;
        head = head->next;
    }
    return ret;
}

double Queue::peek(){
    double ret = 0;
    if(head != NULL){
        ret = head->data;
    }
    return ret;
}

void Queue::print(){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

void Queue::Delete(){
    while(head != NULL){
        Node* tmp = new Node;
        tmp = head;
        head = head->next;
        delete tmp;
    }
    delete head;
}