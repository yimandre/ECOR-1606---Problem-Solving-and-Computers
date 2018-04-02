/* Author:       Prof. B. Chawla
   Subject:      ECOR 1606
   Assignment#2, Question #2
   Purpose:     You are given a certain amount of money, and you are tasked with 
                    buying the most expensive drink available with that amount. */

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

    // Variables
    double a = 0; // Will hold the amount of money available
    double aFood; // The amount of money you want to spend on Food
    double aDrinkl; // The amount of money you want to spend on Drinks

    cout << "Please enter how much money you have available:";
    cin >> a;
    
    cout << "How much money would you like to spend on food?";
    cin >> aFood;
    
    cout << "How much money would you like to spend on drink?";
    cin >> aDrink

    // Go through the list of possible drinks
    // From most expensive to least
    if (a>0 && aDrink>0) {
        // Process valid money amounts
        if (a >= 8.99 && aDrink >= 8.99) {
            cout << "We recommend you purchase an OJ with Carrots & Spinach, for $8.99"
        } else if (a >= 4.99 && aDrink >= 4.99) {
            cout << "We recommend you purchase an OJ, for $4.99";
        } else if (a >= 3.50 && aDrink >=) {
            cout << "We recommend you purchase an Asparagus Milkshake, for $3.50";
        } else if (a >= 2.50) {
            cout << "We recommend you purchase a Strawberry Milkshake, for $2.50";
        } else if (a >= 1.75) {
            cout << "We recommend you purchase a Tea, for $1.75";
        } else if (a >= 1.25) {
            cout << "We recommend you purchase a Water, for $1.25";
        } else if (a >= 0.95) {
            cout << "We recommend you purchase a Coffee, for $0.95";
        } else if (a >= 0.25) {
            cout << "You could purchase a Pop, for $0.25";
        } else {
            cout << "You cannot afford any drink";
        } // end if
    } else {
        // Process invalid money amounts
        cout << "Amount of money entered in error";
    } // end if
    cout << endl;

    system("PAUSE"); return 0;

}
