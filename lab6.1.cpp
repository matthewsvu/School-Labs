#include <iostream>
// iomanip is for setprecision
#include <iomanip>
using namespace std;

int main()
{
    // declare double variables for inputs and average
    double test1, test2, test3, test4, test5, average;

    //gathers input
    cout << "Enter 5 test grades" << endl;
    cin >> test1;
    cin >> test2;
    cin >> test3;
    cin >> test4;
    cin >> test5;
    // computes the average of all tests
    average = (test1 + test2 + test3 + test4 + test5)/5;
    // outputs the average rounded to 1 decimal place
    cout << fixed << setprecision(1) << "Average: " << average << endl;
}
