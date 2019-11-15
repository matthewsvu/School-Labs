#include <iostream>
#include <iomanip>
/*
This program you will be reading in the number of seconds and then calculating how far sound can travel in a
specified medium in that many seconds.
*/
using namespace std;

int main() {
// declares const doubles for air water and steel
const double AIR = 1100;
const double WATER = 4900;
const double STEEL = 16400;

int menuNum;
double distance;

//Creates intial menu that user selects from and reads input from user
cout << "Select the medium that sound is traveling through:\n";
cout << "1 Air" << endl;
cout << "2 Water" << endl;
cout << "3 Steel" << endl;

cin >> menuNum;

switch(menuNum) { // tests for invalid cases and valid cases
    case 1:
        cout << "Enter distance (in feet)\n";
        cin >> distance;
        if(distance <= 0) { // checks to see input for dist is valid
            cout << "The distance must be greater than zero\n";
        } else { // outputs the calculation for dist and air
            cout << fixed << setprecision(4) << "Air: " << distance << " ft\n";
            cout << fixed << setprecision(4) << "Traveled for " << distance / AIR << " seconds\n";
        }
        break; // leaves switch statement
    case 2:
        cout << "Enter distance (in feet)\n";
        cin >> distance;
        if(distance <= 0) { // checks to see input for dist is valid
            cout << "The distance must be greater than zero\n";
        } else { // outputs the calculation for distance and water
            cout << fixed << setprecision(4) << "Water: " << distance << " ft\n";
            cout << fixed << setprecision(4) << "Traveled for " << distance / WATER << " seconds\n";
        }
        break; // leaves switch statement
    case 3:
        cout << "Enter distance (in feet)\n";
        cin >> distance;
        if(distance <= 0) { // checks to see input for dist is valid
            cout << "The distance must be greater than zero\n";
        } else { // outputs the calculaton for distance and steel
            cout << fixed << setprecision(4) << "Steel: " << distance << " ft\n";
            cout << fixed << setprecision(4) << "Traveled for " << distance / STEEL << " seconds\n";
        }
        break; // leaves switch statement
    default: // outputs this when no valid cases found
        cout << "The menu value is invalid. Please run the program again.\n";
        break;

}



}

