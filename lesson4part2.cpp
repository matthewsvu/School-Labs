#include <iostream>
#include <cmath>
/*
Make a program that will read in a given amount of seconds and return it
converted in to days, hours, minutes, and the remaining amount of seconds.
Use long long for all calculations.
*/

using namespace std;

int main() {
long long totalSec, days, hours, minutes;
// read in seconds from user and output it
cout << "Enter seconds\n";
cin >> totalSec;

cout << "Total seconds: " << totalSec << endl << endl;
// tests for invalid case
if(totalSec <= 0) {
    cout <<  "Total seconds must be greater than zero\n";
}
else {
    if(totalSec / 86400 >= 1) { // calc
        days = totalSec / 86400;
        totalSec = totalSec % 86400;
        cout << days << " day(s)\n";
    }
    if(totalSec / 3600 >= 1) {
        hours = totalSec / 3600;
        totalSec = totalSec % 3600;
        cout << hours << " hour(s)\n";
    }
    if(totalSec / 60 >= 1) {
        minutes = totalSec / 60;
        totalSec = totalSec % 60;
        cout << minutes << " minute(s)\n";
    }
    if(totalSec > 0) { // outputs remaining seconds left in totalSec
        cout << totalSec << " second(s)" << endl;
    }
}
}

