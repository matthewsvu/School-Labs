/*
Create a program that reads in two int vals and see if they fit in the range of 32 - 126
if they are, then loop in between the two vals and output the corresponding ASCII character
Make a new line every 20 spaces.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int lower, upper, count = 0;
    bool isValid = false;

    cout << "Enter lower and upper values" << endl;
    cin >> lower >> upper; // read in user input for lower/upper
    while(isValid == false)
    {
        if(lower < 32 || upper > 126 || lower >= 126 || upper <= 32 ) // checks to see if lower and upper are in range
        {
            cout << "Values must be in range 32 to 126 inclusive" << endl;
            cout << "Enter lower and upper values" << endl;
            cin >> lower >> upper;
        }
        else
        {
            // If the value are in range create the ASCII table
            cout << "Characters for ASCII values between " << lower << " and " << upper << endl;
            cout << "----+----+----+----+\n";
            isValid = true;
        }
    }
    for(int i = lower; i <= upper; i++)
    {
        // Starting from the lower num and ending at upper, loop through the numbers and output the ASCII char
        if(count == 20)   // outputs a new line every 20 characters
        {
            cout << "\n";
            count = 0;
        }
        cout << char(i);
        count++; // increment for a new space
    }

    cout << "\n----+----+----+----+\n";
}
