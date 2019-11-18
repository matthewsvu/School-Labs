/*
This program will calculate the future value taken from a present value
, interest rate, and months. Opening a inputfile and outputting valid values to
the output file.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
// future function that calculate future value
double futureValue(double presentValue, double interestRate, int months)
{
    double future = presentValue * pow((1 + interestRate), months);
    return future;
}
// read function that uses reference to main function to read in values
unsigned int readInValue(ifstream &input, double &presentValue, double &interestRate, int &months)
{
    if(input >> presentValue >> interestRate >> months) // reads in file info
    {
        if(presentValue <= 0 || interestRate <= 0 || months <= 0) // checks if info is valid
        {
            cout << fixed << setprecision(2) << presentValue << " " << fixed << setprecision(3) <<
            interestRate << " " << months << endl;
            cout << "One or more of the above values are not greater than zero\n";
            return 2; // returns error val;
        }
        return 1; // if successful returns 1
    }
        return 0; // returns after file is done reading in
}
// output display function uses output as reference in main function
void writeOutput(ofstream &output, double present, double rate, int months)
{
    double interestRate = rate / 100; // divides the rate into interest used to calculate future value
    double future = futureValue(present, interestRate, months);
    output << fixed << setprecision(2) << future << "\t" << present << "\t" <<
    fixed << setprecision(3) << rate << "\t" << months << endl;
}

int main()
{
    ifstream inputFile; // initiates the streams
    ofstream outputFile;
    double presentValue, interestRate;
    int months;

    string inputName, outputName = "output.xls";
    cout << "Enter input file name\n"; // prompts user for file name
    cin >> inputName;
    inputFile.open(inputName.c_str()); // opens file
    if(!inputFile) // if not successful output error message
    {
        cout << "File \"" << inputName << "\" could not be opened\n";
    }

    outputFile.open(outputName.c_str());
    if(!outputFile) // attempts to open output file and if is not open display error message/close inputfile
    {
        cout << "File \"" << outputName << "\" could not be opened\n";
        inputFile.close();
    }
    outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl; // outputs to outputfile after validation checks
    while(true)
    {
        if(readInValue(inputFile, presentValue, interestRate, months) == 0) // breaks out of loop after file reading is finished.
        {
            break;
        }
        writeOutput(outputFile, presentValue, interestRate, months);
    }
    inputFile.close(); // closes files
    outputFile.close();
}
