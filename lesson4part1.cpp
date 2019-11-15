#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* Calculate weight on different planets in newtons using gravity constants
and output the weight. Indicate if the weight is heavy or light based on conditionals
*/
int main() {

    const double earth = 9.81;
    const double moon = 1.62;
    const double venus = 8.87;

    // extract input weight from user
    double mass, weight;
    cout << "Enter the mass in kg" << endl;
    cin >> mass;
    // test for invalid case
    if(mass <= 0 ) {
        cout << fixed << setprecision(4) << "The mass is " << mass << " kg" << endl;
        cout << "The mass must be greater than zero" << endl;
    }
    else
    { // Outputs the table with width and precision factored in.
    cout << fixed << setprecision(4) << "The mass is " << mass << " kg" << endl;
    cout << "Location    " << "Weight (N)" << endl;
    weight = mass * earth; // Saves the weight on earth to output later on in program
    cout << fixed << setprecision(4) << "Earth" << setw(17) << weight << endl;
    cout << fixed << setprecision(4) << "Moon" << setw(18) << mass * moon << endl;
    cout << fixed << setprecision(4) << "Venus" << setw(17) << mass * venus << endl;
    // cases for when the weight in newtons is less than 5 / 1500 or more
    if(weight < 5) {
        cout << "The object is light" << endl;
    } else if(weight >= 1500) {
        cout << "The object is heavy" << endl;
    }
    }

}
