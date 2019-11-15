#include <iostream>
using namespace std;

int main (){
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // version 2: if else
    if (number < 0)
        cout << "You are too negative!";
    else
        cout << "You are good";

    /*if (number < 0)
        cout << "You are too negative!";
    if (number >= 0)
        cout << "You are good";
        */


}
