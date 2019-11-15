/*
Create a program for the hypothetical Acme Wholesale Copper Wire Company.
The Acme company sells spools of copper wiring for $104 each.
Write a program that displays the status of an order.
With 3 functions, a readin, main, and display function
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
// Constant global vars for prices of spools and shipping cost
const double NORMAL_SHIPPING_CHARGE = 12.99;
const double SPOOL_CHARGE = 104.00;
// passes in reference to values in main to readin function
int readSpools(int &numOrder, int &numStock, double &shipCharge)
{
    char yesOrNo;
    cout << "Spools to be ordered" << endl;
    cin >> numOrder; // read in number of spool orders
    while(numOrder < 1) // if invalid value output error and ask again
    {
        cout << "Spools order must be 1 or more" << endl;
        cout << "Spools to be ordered" << endl;
        cin >> numOrder;
    }
    cout << "Spools in stock" << endl;
    cin >> numStock; // read in number in stock
    while(numStock < 0) // invalid error check
    {
        cout << "Spools in stock must be 0 or more" << endl;
        cout << "Spools in stock" << endl;
        cin >> numStock;
    }
    cout << "Special shipping and handling (y or n)" << endl;
    cin >> yesOrNo;
    switch (yesOrNo) // if yes change shipping amount to special ship amount
    {
    case 'y':
        cout << "Shipping and handling amount" << endl;
        cin >> shipCharge;
        if(shipCharge > 0) // leaves if shipCharge is valid
            break;
        while(shipCharge < 0) // invalid error check
        {
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
            cout << "Shipping and handling amount" << endl;
            cin >> shipCharge;
        }
        break;
    default: // defaults to global constant for shipping
        shipCharge = NORMAL_SHIPPING_CHARGE;
        break;
    }
    return 0;
}
// display function
void displaySpools(int numOrder, int numStock, double shipCharge)
{
    // does calculation for backed up orders and orders that are ready to ship
    int backOrder = abs(numOrder - numStock), readyOrder = numOrder - backOrder;
    if(numStock > numOrder) // checks for edge case of stock being greater than orders.
    {
        backOrder = 0;
        readyOrder = numOrder;
    }
    // does calculations for output
    double subtotal = SPOOL_CHARGE * readyOrder;
    double total = subtotal + (shipCharge * readyOrder);
    double shipCost = shipCharge * readyOrder;
    // outputs calculation to a precision of 2
    cout << "Spools ready to ship: " << readyOrder << endl;
    cout << "Spools on back-order: " << backOrder << endl;
    cout << fixed << setprecision(2) << "Subtotal ready to ship: $" << setw(10) << subtotal << endl;
    cout << fixed << setprecision(2) << "Shipping and handling:  $" << setw(10) << shipCost << endl;
    cout << fixed << setprecision(2) << "Total shipping charges: $" << setw(10) << total << endl;
}
// main function
int main()
{
    int numOrder, numStock;
    double shipCharge;
    readSpools(numOrder, numStock, shipCharge); // calls functions and passes in references to variables
    displaySpools(numOrder, numStock, shipCharge);
}
