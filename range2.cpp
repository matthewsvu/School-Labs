#include <iostream>
using namespace std;

int main (){
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(num < 1)
        cout << "You are too negative!";
    else if (num == 0)
        cout << "Don't be a zero";
    else
        cout << "You are good!";


}
