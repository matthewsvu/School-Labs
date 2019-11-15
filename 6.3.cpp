/*
Create a program that will find out the net profit/loss of the purchase and sale
of a inputted companies stock.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declares commission percentage
    const double COMMISSION = 0.035;

    string company = "";
    int stock;
    double purchasePrice, salePrice;
    // gather input from user
    cout << "Enter the name of the company" << endl;
    getline(cin, company);

    cout << "Enter shares of stock" << endl;
    cin >> stock;

    cout << "Enter purchase price" << endl;
    cin >> purchasePrice;

    cout << "Enter sale price" << endl;
    cin >> salePrice;
    cout << endl;

    cout << "Company: " << company << endl;
    cout << "Shares: " << stock << endl << endl;

    // Displays the inputs and calculates the total cost of the stocks
    cout << fixed << setprecision(2) << "Purchase/share: $" << purchasePrice << endl;
    cout << fixed << setprecision(2) << "Cost of stock: $" << purchasePrice * stock << endl;
    cout << fixed << setprecision(2) << "Cost of commission: $" << (purchasePrice * stock) * COMMISSION << endl;
    double totalCost = ((purchasePrice * stock) * COMMISSION) + (purchasePrice * stock);
    cout << fixed << setprecision(2) << "Total cost: $" << totalCost << endl << endl;

    // Displays sale inputs and calculates them to find the total income
    cout << fixed << setprecision(2) << "Sale/share: $" << salePrice << endl;
    cout << fixed << setprecision(2) << "Income from stock: $" << salePrice * stock << endl;
    cout << fixed << setprecision(2) << "Cost of commission: $" << (salePrice * stock) * COMMISSION << endl;
    double totalIncome = (salePrice * stock) - ((salePrice * stock) * COMMISSION);
    cout << fixed << setprecision(2) << "Total income: $" << totalIncome << endl << endl;
    // subtracts the income and cost to find the total gain/loss
    cout << fixed << setprecision(2) <<  "Gain or loss: $" << totalIncome - totalCost << endl;


}
