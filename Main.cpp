/*
    Computer Science 2
    Main file

    Collin Worth 10-24-2023
*/

#include <iostream>
#include <fstream>
#include "Queue.h"
using namespace std;

bool exits;

void storeMaze(int);

int main(){
    exits = false;
    int userChoice = 0;

    Queue q;

    q.Delete();

    cout << q.dequeue() << endl;
    q.enqueue(5);
    q.enqueue(7);
    q.print();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.Delete();

    do{
        cout << "Please select a Maze to solve (1,2,3, exit(\"0\")):" << endl;
        cin >> userChoice;

        storeMaze(userChoice);

    }while(exits == false);


    return 0;
}

void storeMaze(int selection){
    // Open the file for reading

    ifstream inputFile;  // Declare the ifstream object here

    if (selection == 1) {
        inputFile.open("maze1.txt");
    } else if (selection == 2) {
        inputFile.open("maze2.txt");
    } else if (selection == 3) {
        inputFile.open("maze3.txt");
    } else if(selection == 0){
        exits = true;
        return;
    }else{
        cout << "Improper input." << std::endl;
        return;
    }

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << std::endl;
        return;
    }

    int numRows, numCols;
    inputFile >> numRows >> numCols;  // Read the size of the maze

    // Create a dynamically allocated 2D array to store the maze
    char** maze = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        maze[i] = new char[numCols];
    }

    // Read the maze from the file
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            inputFile >> maze[i][j];
        }
    }

    // Close the file
    inputFile.close();

    // Print the maze (optional)
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }

    // Don't forget to deallocate memory when done
    for (int i = 0; i < numRows; i++) {
        delete[] maze[i];
    }
    delete[] maze;
}