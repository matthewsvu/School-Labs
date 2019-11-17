#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double futureValue(double presentValue, double interestRate, int months)
{
    double future = presentValue * pow((1 + interestRate), months);
    return future;
}

unsigned int readInValue(ifstream &input, double &presentValue, double &interestRate, int &months)
{
    string fileName;
    cout << "Enter input file name\n";
    cin >> fileName;
    input.open(fileName.c_str());
    if(!input)
    {
        cout << "File \"" << fileName << "\" could not be opened\n";
        return 2;
    }
    else
    {
        while(input >> presentValue >> interestRate >> months)
        {
            if(presentValue <= 0 || interestRate <= 0 || months <= 0)
            {
                cout << fixed << setprecision(2) << presentValue << " " << fixed << setprecision(3) << interestRate << " " << months << endl;
                cout << "One or more of the above values are not greater than zero\n";
            }
        }
        input.close();
        return 1;
    }
    return 0;
}

int writeOutput(ofstream &output)
{
    string outputFileName = "output.xls";
    output.open(outputFileName.c_str());
    output <<  "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
    output.close();
    return 0;

}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    double presentValue, interestRate;
    int months;

    readInValue(inputFile, presentValue, interestRate, months);
    writeOutput(outputFile);
}
