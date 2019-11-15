/*
Create a program that reads in two int vals and see if they fit in the range of 32 - 126
if they are, then loop in between the two vals and output the corresponding ASCII character
Make a new line every 20 spaces.
*/

#include <iostream>
using namespace std;

int main()
{
    int lower, upper, count;

    cout << "Enter upper and lower values: ";
    cin >> lower >> upper; // read in user input for lower/upper

    if(lower < 32 || upper > 126) // checks to see if lower and upper are in range
    {
        cout << "Values must be in range 32 to 126 inclusive" << endl;
    }
    else
    {   // If the value are in range create the ASCII table
        cout << "Characters for ASCII values between " << lower << " and " << upper << endl;
        cout << "----+----+----+----+\n";

        for(int i = lower; i <= upper; i++)
        { // Starting from the lower num and ending at upper, loop through the numbers and output the ASCII char
            cout << char(i);
            if(count % 20 == 1) // Checks to see if 20 spaces has passed, creates a new line if so
            {
                cout << endl;
            }
            count++; // increment for a new space
        }
        cout << endl << "----+----+----+----+\n";
    }
    return 0;
}
