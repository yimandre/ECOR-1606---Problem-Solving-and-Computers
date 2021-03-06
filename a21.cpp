/* Andre Yim
   100961929
   
   ECOR 1606 ASSIGNMENT 2
   QUESTION 1 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) {
    return value * value;
}

int main (void) {

    // Constants
    const double a = 8.99, // Orange Juice with Diced Carrots & Spinach
                 b = 4.99, // Orange Juice
                 c = 3.50, // Asparagus Milkshake
                 d = 2.50, // Strawberry Milkshake
                 e = 1.75, // Tea
                 f = 1.25, // Water
                 g = 0.95, // Coffee
                 h = 0.25; // Pop

    // Variables
    double value;

    cout << "Please enter how much money you have available: ";
    cin >> value;

    if (value >= a) {
        cout << "We recommend you purchase an Orange Juice with Carrots & Spinach, for" << a << endl;
    } else if (value >= b) {
        cout << "We recommend you purchase an Orange Juice, for " << b << endl;
    } else if (value >= c) {
        cout << "We recommend you purchase an Asparagus Milkshake, for " << c << endl;
    } else if (value >= d) {
        cout << "We recommend you purchase a Strawberry Milkshake, for " << d << endl;
    } else if (value >= e) {
        cout << "We recommend you purchase a Tea, for " << f << endl;
    } else if (value >= f) {
        cout << "We recommend you purchase a tea, for " << f << endl;
    } else if (value >= g) {
        cout << "We recommend you purchase a Water, for " << g << endl;
    } else if (value >= h) {
        cout << "We recommend you purchase a Pop, for " << h << endl;
    } else {
        cout << "You cannot afford any drink" << endl;
    } // end if

    system("PAUSE"); return 0;

}
