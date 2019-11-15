#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

void readConfiguration()   // creates allocates data into arrays
{
    ifstream file("menu.txt");
    for(int i = 0; i < MAXPRODUCTS; ++i)
    {
        file >> codes[i] >> names[i] >> prices[i];
    }
}

//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode)
{
    for(int i = 0; i < MAXPRODUCTS; i++)
    {
        if(inputCode == codes[i])
        {
            return i;
        }
    }
    return -1;
}

// read order string like "A1 A1 E1 E2 S1" and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process()
{
    string inputCode;
    int index;
    double total = 0;
    while(cin >> inputCode)
    {
        index = findItem(inputCode);
        if(inputCode == "end")
            break;
        if(index == -1)
        {
            cout << inputCode << " is invalid. Skipping it." << endl;
        }
        else
        {
            cout << fixed << setprecision(2) <<  names[index] << ": $" << prices[index] << endl;
            total += prices[index];
        }
    }
    cout << fixed << setprecision(2) << "Total: $" << total;
}

int main()
{
    readConfiguration();
    process();
}
