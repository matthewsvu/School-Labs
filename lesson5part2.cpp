#include <iostream>
#include <iomanip>

using namespace std;

/*
Your program will read in the menu number as an unsigned int value .
The menu item must be processed using a if / else / else if statements.
The seconds value and all calculations need to be done using double values.
*/

int main()
{
    const double CARBON = 258.0;
    const double AIR = 331.5;
    const double HELIUM = 972.0;
    const double HYDROGEN = 1270.0;
    //Declare const vars for calculation and creates the variables derived from user input
    int menuNum;
    double distance;
    double time;
    bool isValid = true;
    // Creates menu for user to choose
    cout << "Select the medium that sound is traveling through:\n";
    cout << "1 Carbon Dioxide" << endl;
    cout << "2 Air" << endl;
    cout << "3 Helium" << endl;
    cout << "4 Hydrogen" << endl;
    // Retrievess user input
    cin >> menuNum;

    if(menuNum <= 0 || menuNum > 4)
    {
        isValid = false; // checks to see user input is between 0 and 4
        cout << "The menu value is invalid. Please run the program again.\n";
    }
    if(isValid)   // if user input is valid gather time inout
    {
        cout << "Enter time (in seconds)\n";
        cin >> time;
        if(time < 0 || time > 30)   // time must be in this interval
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)\n";
        }
        else     // if time is valid output the calculations for time and distanced traveled
        {
            if(menuNum == 1)
            {
                cout << fixed << setprecision(3) << "Carbon Dioxide: " << time << " seconds\n"; // outputs user time input
                distance = time * CARBON; // calculates distance
            }
            else if (menuNum == 2)
            {
                cout << fixed << setprecision(3) << "Air: " << time << " seconds\n";
                distance = time * AIR;
            }
            else if (menuNum == 3)
            {
                cout << fixed << setprecision(3) << "Helium: " << time << " seconds\n";
                distance = time * HELIUM;
            }
            else
            {
                cout << fixed << setprecision(3) << "Hydrogen: " << time << " seconds\n";
                distance = time * HYDROGEN;
            }
            cout << fixed << setprecision(4) << "Traveled " << distance << " meters\n"; // output for distance
        }
    }
}
