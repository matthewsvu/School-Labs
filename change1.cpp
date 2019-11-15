#include <iostream>
using namespace std;

int main() {

   const int dollar = 100;
   const int quarter = 25;
   const int dime = 10;
   const int nickel = 5;
   const int penny = 1;


   int dollarNum = 0;
   int quarterNum = 0;
   int dimeNum = 0;
   int nickelNum = 0;
   int pennyNum =0;

   int money;

   cin >> money;

   if (money >= dollar) {
    dollarNum = dollarNum + 1;
    money = money - dollar;
    cout << dollarNum << " dollar" << endl;
   }
   else if (money >= quarter) {
    quarterNum = quarterNum + 1;
    money = money - quarter;
    cout << quarterNum << " quarter" << endl;
   }
   else if (money >= dime) {
    dimeNum = dimeNum + 1;
    money = money - dime;
    cout << dimeNum << " dime" << endl;
   }
   else if (money >= nickel) {
     nickelNum = nickelNum + 1;
    money = money - nickel;
    cout << " nickel" << endl;
   }
   else if (money >= penny) {
    pennyNum = pennyNum + 1;
    money = money - penny;
    cout << pennyNum <<" penny" << endl;
   }
   else {
   cout << "no change" << endl;
   }

   return 0;
}
