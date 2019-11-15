#include <iostream>
using namespace std;

int main (){
    int num;

    cout << "Enter a number between 1-100: ";
    cin >> num;

    if(num < 1)
        cout << num << " is outside the range!";
    else if (num > 100)
        cout << num << " is outside the range!";
    else
        cout << "You are good!";

}
