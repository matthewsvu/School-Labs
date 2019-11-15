/*
Create a program that will read three double values and create a table that will
increment by the 3rd double value stopping after it surpassed the 2nd double val.
The program will convert fahrenheit to celsius and Kelvin.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double firstTemp, endTemp, increment;

    cin >> firstTemp >> endTemp >> increment; // declare and read in user input

    while(true)
    {
        if(firstTemp > endTemp || increment <= 0) // checks to see if user input is in range
        {
            cout << "Starting temperature must be <= ending temperature and increment must be > 0.0\n";
            cin >> firstTemp >> endTemp >> increment;
        }
        else
        {
            break; // leaves loop once input is in range
        }
    }
    cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(19) << "Kelvin\n"; // makes table
    while(true)
    {
        if(firstTemp > endTemp) // checks to see if input goes out of bound and leave function after
        {
            break;
        }
        double celsius = (firstTemp - 32) / 1.8; // calculates the celsius and kelvin vals
        double kelvin = celsius + 273.15;

        cout << fixed << setprecision(4) << setw(18) << firstTemp << setw(18) << celsius  << setw(18) << kelvin << endl; // outputs the calculations
        firstTemp = firstTemp + increment; // increments the firstTemp
    }


}
