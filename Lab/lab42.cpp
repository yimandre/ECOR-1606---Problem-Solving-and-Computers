// Lab 4
// Part 2
// Name: Andre Yim
// Student Number: 100961929

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

double sqr(double value) { 
	return value * value; 
}

int main (void) {

  // Variables
  double number;
  double divider;

  cout << "Enter a number: ";
  cin >> number;
  
  cout << "The binary equivalent of " << number << " is ";
  
  
  while (2 * divider <= number) {
    divider = divider * 2;
  } // end while

  while (divider >= 1); {
    if (number < divider) {
      cout << "1";
      number == number - divider;
  } else; {
		cout << "0";
    } // end if
    divider = divider / 2;
  } // end while


    system("PAUSE"); return 0;
}
