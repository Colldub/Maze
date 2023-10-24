#include <iostream>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
int A[MAX_ROWS][MAX_COLS];

void PrintArray(int, int);
void InitArray(int, int);
void ReadArray(int, int);

int main(){
    int nRows = 3;
    int nCols = 3;

    InitArray( nRows, nCols );
    PrintArray( nRows, nCols);
    ReadArray();

    return 0;
}

void InitArray( int nRows, int nCols){
    for(int i = 0; i < nRows; i ++){
        for( int j = 0; j < nCols; j ++){
            A[i][j] = i + j;
        }
    }
}

void ReadArray(int nRows, int nCols){
    ifstream fIn;
    fIn.open( "test.dat", ios::in )
    for(int i = 0; i < nRows; i ++){
        for( int j = 0; j < nCols; j ++){
            fIn >> tmp;
            cout >> tmp;
            A[i][j] = tmp;
        }
    }
}

void PrintArray(int nRows, int nCols){
    for(int i = 0; i < nRows; i ++){
        for( int j = 0; j < nCols; j ++){
            cout << A[i][j] = i + j << endl;
        }
    }
}