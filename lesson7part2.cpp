/*
Create program that will find average of numbers in a file. That you will open
and check if it is within the bound 0 to 105.
Close the file and its outputs file after finishing.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int totalNum = 0, invalidNum = 0, validNum = 0;
    double num, averageNum = 0;
    string fileName;

    cout << "Enter input file name" << endl;
    cin >> fileName; // get file name

    inputFile.open(fileName.c_str()); // allows file to open string
    if(!inputFile) // checks to see if file opens and exits if it is not
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl;
        exit(EXIT_SUCCESS);
    }

    cout << "Reading from file \"" << fileName << "\"\n";
    outputFile.open("invalid-values.txt"); // opens invalid files output file
    while(inputFile >> num) // reads in the numbers in file
    {
        totalNum++; // counts the total amount of numbers
        if(num < 0 || num > 105)
        {
            invalidNum++;
            outputFile << fixed << setprecision(5) << num << endl; // output num to outputfile if in not in range
        }
        else
        {
            validNum++;
            averageNum += num; // used for calculating average of valid num
        }
    }
    // Create table and output the values
    cout << "Total values: " << totalNum << endl;
    cout << "Invalid values: " << invalidNum << endl;
    cout << "Valid values: " << validNum << endl;
    // checks to see if average is calculable and if not say it cannot be calced
    if(validNum == 0)
    {
        cout << "An average cannot be calculated" << endl;
    }
    else
    {
        cout << fixed << setprecision(4) << "Average of valid values: " << averageNum / validNum << endl;
    }
    outputFile.close(); // close files
    inputFile.close();

}
