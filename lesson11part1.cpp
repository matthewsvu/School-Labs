/*
Make a program that will validate a loshu magic square with sizes between
3x3 and 21x21. There must be every number from 1 to n times in the square
and the program must open and close all files.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_SIZE = 21;

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName) // reads in file name
{
    int realSize; // calculates real size
    ifstream finput; // initialize input stream

    finput.open(inputFileName.c_str());
    if(!finput) { // if file does not open return 0
        return 0;
    }
    finput >> realSize; // read in the length of one side
    for(int i = 0; i < realSize; i++) // loops through the matrix and reads in the value for all of possible values
    {
        for(int j = 0; j < realSize; j++)
        {
            finput >> square[i][j];
        }
    }
    finput.close(); //close file
    realSize = realSize * realSize; // finds the total size of the array 3*3 = 9 total values
    return realSize;
}

bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size)
{
    int length = sqrt(size); // the length of one side of the matrix
    int sum = (length * (length * length + 1)) / 2; // what the sum should be of the row/column/diagonal
    int rowSum = 0, columnSum = 0, leftDiagonalSum = 0, rightDiagonalSum = 0;

    for(int j = 0; j < length; j++) { // checks the row sum
         columnSum += square[j][length-1];
    }
    for(int i = 0; i < length; i++) { // checks the column sum.
        rowSum += square[length-1][i];
    }
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(square[i][j] == square[i+1][j+1] || square[i][j] == square[i+2][j+2]) { // checks to see if there is any values that are duplicates of each other diagonally
                return false;
            }
             leftDiagonalSum += square[(length-1)-i][(length-1)-j]; // adds diagonal sum for the left
             rightDiagonalSum += square[i][(length-1)-j]; // for the right
        }
    }
    leftDiagonalSum /= length;
    rightDiagonalSum /= length; // divides the sum by length
    if(leftDiagonalSum == sum && rightDiagonalSum == sum && columnSum == sum && rowSum == sum) { // return true when all of these vals equal the sum
        return true;
    }
    if(sum == length && columnSum == sum && rowSum == sum) { // return true if sum is length meaning that the arrau is just 1 value
        return true;
    }
    return false;


}

void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size) // loops through the values in square and display them in order.
{
    cout << "Magic square\n";
    int sideLength = sqrt(size);

    for(int i = 0; i < sideLength; i++) { // the loop
        for(int j = 0; j < sideLength; j++) {
            cout << square[i][j]; // display
            if(j == sideLength - 1) { // adds new line right before loop ends
                cout << endl;
            }
        }
    }
    cout << endl;
}

int main()
{
    int loshuSquare[MAX_SIZE][MAX_SIZE]; // initialize the loshu square
    string inputFileName;

    cout << "Enter input file name\n"; // ask for file name
    cin >> inputFileName;
    int filledSquare = readSquare(loshuSquare, inputFileName); // reads the square into the 2d array

    if(filledSquare == 0)
    {
        cout << "File \"" << inputFileName << "\" could not be opened\n"; // checks if file opened
    }
    else
    {
        displaySquare(loshuSquare, filledSquare); // displays square
        if(validateSquare(loshuSquare, filledSquare) == true) // checks if it valid square
        {
            cout << "Valid magic square\n";
        }
        else
        {
            cout << "Invalid magic square\n";
        }
    }
}
