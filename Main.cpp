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
char** maze;
char** visited;
int numRows, numCols;
bool loaded;
Queue q;

void storeMaze(int);
void DeleteMaze();
bool nextToExit(int, int);
void PrintMaze();
void createVisit();
void addNeighboors(int, int);
void PrintVisited();
void DeleteVisited();

int main(){
    int currentR;
    int currentC;
    int newR;
    int newC;
    exits = false;
    int userChoice = 0;
    loaded = false;

    


    do{
        cout << "Please select a Maze to solve (1,2,3, exit(\"0\")):" << endl;
        cin >> userChoice;
        //choses maze and store in 2d array
        storeMaze(userChoice);

        createVisit();

        PrintMaze();
        currentR = -1;
        currentC = -1;
        ///////////////// Find start
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (maze[row][col] == 'S') {
                    currentR = row;
                    currentC = col;
                    break;  // Exit the loop once 's' is found.
            }
        }
            if (currentR != -1){
                break;
            }
        }
        /////////////////

        //If the current cell is adjacent to the exit, stop.
        while(nextToExit(currentR, currentC) != true){
        //Mark the current cell as visited.
            visited[currentR][currentC] = '1';
        //Add all unvisited neighbors to the north, east, south, and west to a queue.
            addNeighboors(currentR, currentC);
        //Remove the next element from the queue and make it the current cell.
            newR = q.dequeue();
            newC = q.dequeue();
            currentR = newR;
            currentC = newC;
            ///////
            //test ++;
            //if(test == 5000){PrintVisited(); break;}
            
        }
        PrintVisited();
        DeleteMaze();
        DeleteVisited();
    

    }while(exits == false);
    q.Delete();


    return 0;
}

void addNeighboors(int curR, int curC){
    int newCurR;
    int newCurC;
    char nCell, eCell, sCell, wCell;

    // Check the northern neighbor
    if (curR > 0 && maze[curR - 1][curC] == '.' && visited[curR - 1][curC] == '0') {
        q.enqueue(curR - 1);
        q.enqueue(curC);
    }

    // Check the eastern neighbor
    if (curC < numCols - 1 && maze[curR][curC + 1] == '.' && visited[curR][curC + 1] == '0') {
        q.enqueue(curR);
        q.enqueue(curC + 1);
    }

    // Check the southern neighbor
    if (curR < numRows - 1 && maze[curR + 1][curC] == '.' && visited[curR + 1][curC] == '0') {
        q.enqueue(curR + 1);
        q.enqueue(curC);
    }

    // Check the western neighbor
    if (curC > 0 && maze[curR][curC - 1] == '.' && visited[curR][curC - 1] == '0') {
        q.enqueue(curR);
        q.enqueue(curC - 1);
    }
}

void createVisit(){

    visited = new char*[numRows];
    for (int i = 0; i < numRows; i++) {
        visited[i] = new char[numCols];
    }   

    for(int r = 0; r < numRows; r ++){
        for(int c = 0; c < numCols; c ++){
            visited[r][c] = '0'; 
        }
    }
}

bool nextToExit(int curR, int curC){
    char nCell, eCell, sCell, wCell;

    if(curR > 0){
        nCell = maze[curR - 1][curC];
    }
    if(curC < numCols - 1){
        eCell = maze[curR][curC + 1];
    }
    if(curR < numRows - 1){
        sCell = maze[curR + 1][curC];
    }
    if(curC > 0){
        wCell = maze[curR][curC - 1];
    }

    if(nCell == 'G' || eCell == 'G' || sCell == 'G' || wCell == 'G'){
        cout << "you found the end" << endl;
        return true;
    }else{
        return false;
    }
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

    inputFile >> numRows >> numCols;  // Read the size of the maze

    // Create a dynamically allocated 2D array to store the maze
    maze = new char*[numRows];
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

    //state that maze is loaded in the array
    loaded = true;

}

void PrintMaze(){
    // Print the maze
    if (loaded == false)
    {
        return;
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void PrintVisited(){
    // Print the visited maze
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }
}

void DeleteMaze(){
    // Dealocate Memory
    if (loaded == false)
    {
        return;
    }

    for (int i = 0; i < numRows; i++) {
        delete[] maze[i];
    }
    delete[] maze;
    loaded = false;
}

void DeleteVisited(){
    // Dealocate Memory

    for (int i = 0; i < numRows; i++) {
        delete[] visited[i];
    }
    delete[] visited;
    
}