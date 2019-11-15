#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const double NORMAL_SHIPPING_CHARGE = 12.99;
const double SPOOL_CHARGE = 104.00;

int readSpools(int &numOrder, int &numStock, double &shipCharge)
{
    char yesOrNo;
    cout << "Spools to be ordered" << endl;
    cin >> numOrder;
    while(numOrder < 1)
    {
        cout << "Spools order must be 1 or more" << endl;
        cout << "Spools to be ordered" << endl;
        cin >> numOrder;
    }
    cout << "Spools in stock" << endl;
    cin >> numStock;
    while(numStock < 0)
    {
        cout << "Spools in stock must be 0 or more" << endl;
        cout << "Spools in stock" << endl;
        cin >> numStock;
    }
    cout << "Special shipping and handling (y or n)" << endl;
    cin >> yesOrNo;
    switch (yesOrNo)
    {
    case 'y':
        cout << "Shipping and handling amount" << endl;
        cin >> shipCharge;
        if(shipCharge > 0)
            return 0;
        while(shipCharge < 0)
        {
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
            cout << "Shipping and handling amount" << endl;
            cin >> shipCharge;
        }
        return 0;
        break;
    case 'n':
        shipCharge = NORMAL_SHIPPING_CHARGE;
        return 0;
        break;
    default:
        shipCharge = NORMAL_SHIPPING_CHARGE;
        return 0;
        break;
    }
    return 0;
}

void displaySpools(int numOrder, int numStock, double shipCharge)
{
    double subtotal = 0, total = 0;
    int backOrder = abs(numOrder - numStock), readyOrder = numOrder - backOrder;
    if(numStock > numOrder)
    {
        backOrder = 0;
        readyOrder = numOrder;
    }
    cout << "Spools ready to ship: " << readyOrder << endl;
    cout << "Spools on back-order: " << backOrder << endl;
    subtotal = SPOOL_CHARGE * readyOrder;
    cout << fixed << setprecision(2) << "Subtotal ready to ship: $" << setw(10) << subtotal << endl;
    cout << fixed << setprecision(2) << "Shipping and handling:  $" << setw(10) << shipCharge * readyOrder << endl;
    total = subtotal + (shipCharge * readyOrder);
    cout << fixed << setprecision(2) << "Total shipping charges: $" << setw(10) << total << endl;

}

int main()
{
    int numOrder = 0, numStock = 0;
    double shipCharge = 0, total = 0, subTotal = 0;
    readSpools(numOrder, numStock, shipCharge);
    displaySpools(numOrder, numStock, shipCharge);
}
