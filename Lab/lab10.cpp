#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


// Complete function readPolynomial below.
//
// This function starts by asking the user for the order of the polynomial.  
// If the order entered is not between 1 and maxOrder, it will continue to ask 
// for the order, until a valid order is obtained.
// Then it asks the user for the coefficient for the order (which cannot be 0),
// followed by the coefficient for each power of x, down to 0.
// It puts the coefficients in the polynomial array and returns the order
// of the polynomial.
int readPolynomial (int maxOrder, double polynomial[]) {
	
	// you should remove the "return 0;" once you have the function working
	return 0;
}

// Complete function displayPolynomial below.
//
// This function outputs the polynomial of order n in a nice format (as per
// the sample executable).
void displayPolynomial (int order, double polynomial[]) {
	
}

int main () {

	const int MAXN = 8; // maximum order (a constant)
	double polynomial[MAXN + 1];
	int polynomialN;

	// read in the polynomial
	polynomialN = readPolynomial (MAXN, polynomial);

	// output message
	cout << "\nThe polynomial (order = " << polynomialN << ") is\n";
	// followed by the polynomial
	displayPolynomial (polynomialN, polynomial);

	cout << endl;
	system("PAUSE"); return 0;

}

