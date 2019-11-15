#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fizzBuzz()
{
    int threeCount = 0;
    int fiveCount = 0;
    int bothCount = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            bothCount++;
            cout << "FizzBuzz " << i << endl;
        }
        else
        {
            if(i % 3 == 0)
            {
                threeCount++;
                cout << "Fizz " << i << endl;
            }
            if(i % 5 == 0)
            {
                fiveCount++;
                cout << "Buzz " << i << endl;
            }
        }
    }
    cout << "Amount of Fizz: " << threeCount << endl;
    cout << "Amount of Buzz: " << fiveCount << endl;
    cout << "Amount of FizzBuzz: " << bothCount << endl;
}

int main()
{
    fizzBuzz();

}
