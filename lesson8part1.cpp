/*
Make a program using functions that will read in a input greater than or equal to zero
for seconds. This value will be read into other functions that will calculate the distance between the earth and moon..
Display these results in a properly formatted manner of 4 decimals places and two decimals places
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double readSeconds()   // function reads in
{
    double seconds;
    cout << "Enter the time (in seconds)\n";
    cin >> seconds;
    if(seconds < 0)
    {
        cout << "The time must be zero or more" << endl;
        seconds = readSeconds(); // recursively calls readseconds in the case of input being out of range
    }
    else   // returns seconds if in range
    {
        return seconds;
    }
    return seconds;
}

double calculateEarthDistance(double seconds) // calculates earth distance using formula and return the value
{
    double gravity = 9.8, time = seconds;

    double dist = 0.5 * gravity * pow(time, 2);
    return dist;
}

double calculateMoonDistance(double seconds) // calculates moon distance using formula and returns it
{
    double gravity = 1.6, time = seconds;

    double dist = 0.5 * gravity * pow(time, 2);
    return dist;
}

void displayResults(double seconds, double earthDistance, double moonDistance) // display values in formatted manner
{
    cout << fixed << setprecision(4) << "The object traveled " << earthDistance << " meters in ";
    cout << fixed << setprecision(2) << seconds << " seconds on Earth\n";
    cout << fixed << setprecision(4) << "The object traveled " << moonDistance << " meters in ";
    cout << fixed << setprecision(2) << seconds << " seconds on the Moon\n";
}
// main function
int main()
{
    double seconds, moonDistance, earthDistance;

    while(true) // while seconds is not 0 keep calling the amount of seconds and executing the moondist, earthdist functions
    {
        seconds = readSeconds();
        if(seconds == 0)
        {
            break;
        }
        else
        {
            earthDistance = calculateEarthDistance(seconds);
            moonDistance = calculateMoonDistance(seconds);
            displayResults(seconds, earthDistance, moonDistance);
        }
    }
}
