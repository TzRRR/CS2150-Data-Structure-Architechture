//Tianze Ren, tr2bx, 10/19/2022, wordPuzzle.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hashTable.h"


using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


int main (int argc, char* argv[]){
//    timer t;
//    t.start();
    
    
    ifstream file(argv[1]);
    vector<string> words;
    int sizetrack = 0;
    string input;
    while (getline(file, input)){
        words.push_back(input);
        sizetrack++;
    }


    hashTable h = hashTable(sizetrack);

    for (int i = 0; i < sizetrack; i++){
        h.insert(words[i]);
    }

    int rows;
    int cols;
    int num = 0;
    string word;
    string direction[] = {"N","NE","E","SE","S","SW","W","NW"};
    readInGrid(argv[2],rows, cols);

    for (int a = 0; a < rows; a++){
        for (int b = 0; b < cols; b++){
            for (int c = 0; c < 8; c++){
                for (int d = 3; d <= min(max(rows, cols), 22); d++){
                    word = getWordInGrid(a, b, c, d, rows, cols);
                    if(word.length()<d){
                        break;
                    }
                    if (h.find(word)){
                        cout << direction[c] << "(" << a << ", " << b
                        << "): " << word << endl;
                        num++;
                    }
                }
            }
        }
    }

    cout<< num <<" words found"<<endl;
    
//    t.stop();
//    cout << int(t.getTime()*1000) << endl;

    return 0;

}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
//    cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
//    cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
//        cout << endl;
    }
    return true;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
