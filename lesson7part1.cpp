/*
Create a program that will open a file and read in data that read in a store numbers and the sales
data from that store. Output the ALL valid sales data in to the saleschart.txt file. The store num and
sales data must not be negative or out of the range.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    string name;
    ifstream inputFile;
    ofstream outputFile;
    int storeNum, count = 0;
    long long int salesData;

    cout << "Enter input file name" << endl; // read in file name
    cin>> name;


    inputFile.open(name.c_str()); // opens at a string

    if(inputFile) // if file is open
    {
        outputFile.open("saleschart.txt"); // open outputfile
          if(!outputFile) { // if output file is not open close inputfile
             inputFile.close();
             cout << "File saleschart.txt could not be opened" << endl;
        }
    }
    else
    {
        cout << "File \"" << name << "\" could not be opened" << endl;
        exit(EXIT_SUCCESS); // leaves program if file can't be opened.
    }
    while(inputFile >> storeNum >> salesData) // read in the store num and sales data from inputfile
    {
        count++; // increment for a sales bar chart
        if(salesData < 0) { // checks if in range
            cout << "The sales value for store " << storeNum << " is negative\n";
        }
       else if(storeNum < 1 || storeNum > 99) // checks if in range
        {
            cout << "The store number " << storeNum << " is not valid\n";
        } else {
            if(count == 1) {
                outputFile << "SALES BAR CHART\n" << "(Each * equals 5,000 dollars)\n"; // output the sales bar chart only once
            }
                outputFile << "Store" << setw(3) << storeNum << ": ";
                for(int j = 0; j < salesData / 5000; j++) { // outputs an asterisk every salesdata num / 5000
                outputFile << "*";
                }
                outputFile << "\n";
            }
    }
    inputFile.close(); // closes files
    outputFile.close();
    return 0;
}
