/*
Program will fill out a 2d array and find the smallest values in each row
find the average of the numbers within the 2d array, find the average for each column
and display them to the user.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_COLUMNS = 5; // max columns in array

// read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
    ifstream finput; // stream declaration
    int numRows = 0; // var that counts rows to be returned
    finput.open(inputFileName.c_str()); //  // opens file
    if(!finput) // if file not open return -1
    {
        return -1;
    }
    for(int j = 0; j < maxRows; j++) // traverses row and columns of array
    {
        for(int i = 0; i < MAX_COLUMNS; i++)
        {
            if(finput.eof()) // closes file and returns row after file is done being read in
            {
                finput.close();
                return numRows;
            }
            else
            {
                finput >> values[j][i]; // reads in file content into array
            }
        }
        numRows++; // increment row num
    }
    finput.close(); // closes in the case of edge case
    return numRows;
}
// for the average in array
double average(double values[][MAX_COLUMNS], int numberRows)
{
    double sum = 0;
    double total = MAX_COLUMNS * numberRows; // calcs the total num of columns
    for(int j = 0; j < numberRows; j++) // // traverses y axis of array
    {
        for(int i = 0; i < MAX_COLUMNS; i++) // traverses x axis and adds values together
        {
            sum += values[j][i];
        }
    }
    double average = sum / total; // returns the average
    return average;
}
// average for a specified column (column)
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
    double sum = 0, average;
    for(int i = 0; i < numberRows; i++) // traverses the y axis of 2d array and adds it to sum
    {
        sum += values[i][column]; // adds them together
    }
    average = sum / numberRows; // gets average by dividing by number of rows
    return average;
}
// find smallest val in row
double smallestRowValue(double values[][MAX_COLUMNS], int row)
{
    double small = values[row][0]; // sets the first value in row to the smallest
    for(int i = 0; i < MAX_COLUMNS; i++) // traverses x axis of 2d array
    {
        if(small > values[row][i]) // checks if the next column has lower value
        {
            small = values[row][i]; // sets smallest value equal to current position.
        }
    }
    return small;
}

int main()
{
    const int MAX_ROWS = 30; // const for num of rows
    string inputFileName;
    double grades[MAX_ROWS][MAX_COLUMNS]; // declares 2D array//

    cout << "Enter input file name\n"; // prompt user for file name
    cin >> inputFileName;

    int actualRows = readFile(grades, MAX_ROWS, inputFileName);
    if(actualRows == -1) // if file does not open exit and display error message
    {
        cout << "File \"" << inputFileName << "\" could not be opened\n";
        exit(1);
    }
    if(actualRows == 0) // no rows means no content in file, which means you exit
    {
        cout << "The input file \"" << inputFileName << "\" did not contain any data\n";
    }
    else
    {
        double averageVal = average(grades, actualRows); // calls average value function of all contents in file
        cout << "Processing " << actualRows << " rows, and 5 columns\n";
        cout << fixed << setprecision(2) << "Average for all values is " << averageVal << endl;

        for(int i = 0; i < MAX_COLUMNS; i++) // repeats max columns number of times
        {
            cout << "Average for column " << i << " is " << columnAverage(grades, i, actualRows)<< endl; // calls column average function
        }
        for(int j = 0; j < actualRows; j++) // repeats actual number of time
        {
            cout << "Smallest value for row " << j << " is " << smallestRowValue(grades, j) << endl; // call small val row function
        }
    }
}
