/*
    Computer Science 2
    Queues Header File

    Collin Worth 10-24-2023
*/

#ifndef Queue_H
#define Queue_H
using namespace std;

class Queue {
public:
    Queue(); // Constructor
    ~Queue(); // Destructor

    void enqueue(double);
    double dequeue();
    double peek();
    void print();
    void Delete();

    struct Node {
        double data;
        Node* next;
    };
    Node* head;
};

#endif