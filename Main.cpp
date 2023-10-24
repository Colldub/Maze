/*
    Computer Science 2
    Main file

    Collin Worth 10-24-2023
*/

#include <iostream>
#include "Queue.h"
using namespace std;

int main(){

    Queue q;

    q.Delete();

    cout << q.dequeue() << endl;
    q.enqueue(5);
    q.enqueue(7);
    q.print();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.Delete();


    return 0;
}