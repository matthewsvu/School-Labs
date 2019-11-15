/*
Create a program that will read in a future value that will check to see if it is in range
it will return the future value and do a similar process for the interest rate, num years and present value functions
Make a display function to that will take those values in and display in a formatted manner.
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getFutureValues() // reads in future val and returns the future value if in range
{
    double futureVal;
    cout << "Enter future value" << endl;
    cin >> futureVal;
    if(futureVal <= 0)
    {
        cout << "The future value must be greater than zero" << endl;
    }
    return futureVal;
}
double getInterestRates() // returns interest rate if in range
{
    double rate;
    cout << "Enter annual interest rate" << endl;
    cin >> rate;
    if(rate <= 0)
    {
        cout << "The annual interest rate must be greater than zero" << endl;
    }
    rate = rate / 100; // returns rate as a decimal
    return rate;
}
int getNumYears() // return num years if in range
{
    int years;
    cout << "Enter number of years\n";
    cin >> years;
    if(years <= 0)
    {
        cout << "The number of years must be greater than zero" << endl;
    }
    return years;
}
double presentValue(double futureValue, double interestRate, int numberYears) // returns present value by reading in the previous values and calculating them
{
    double presentVal;
    presentVal = futureValue / pow((1+interestRate),numberYears);
    return presentVal;
}
void displayValue(double presentValue, double futureValue, double interestRate, int numberYears) // function used to display the vars in two or three decimal places
{
    cout << fixed << setprecision(2) << "Present value: $" << presentValue << endl;
    cout << "Future value: $" << futureValue << endl;
    double rate = interestRate * 100; // displays rate as a percentage
    cout << fixed << setprecision(3) <<  "Annual interest rate: " << rate << "%" << endl;
    cout << "Years: " << numberYears << endl;
}
// main function
int main()
{
    double future = 0, interest = 0, present = 0;
    int numberYears = 0;

    while(future <= 0) // calls the future val function
    {
        future = getFutureValues();
    }
    while(interest <= 0) // calls interest rate class
    {
        interest = getInterestRates();
    }
    while (numberYears <= 0) // num years function
    {
        numberYears = getNumYears();
    }
    present = presentValue(future, interest, numberYears); // retrieves present val from presentVal function
    displayValue(present, future, interest, numberYears); // displays end vals
    return 0;
}
