// Lab 4
// Part 1
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

    // INSERT YOUR CONSTANT DECLARATIONS HERE
    const double MAXERROR=0.000001;

    // INSERT YOUR VARIABLE DECLARATIONS HERE
    double xold,xnew,N,error;

    // INSERT YOUR STATEMENTS HERE
    
    
    // prompt user for a value
    // ensure they did not enter a negative number
	do {
		cout << "Please enter a positive number (0 to exit): ";
		cin >> N;
	} while (N<0);
	
	while (N!=0) {

		// set up for while loop
		xold=N;
		do {
			xnew=(xold+N/xold)/2;
			error=fabs(xold-xnew);
			xold=xnew;
			// test error are repeat the while loop as needed
		} while(error>MAXERROR);

		// output the result
	    cout << "Square root of " << N << " is " << xnew << endl;
	    // prompt user for a value
	    // ensure they did not enter a negative number
		do {
			cout << "Please enter a positive number (0 to exit): ";
			cin >> N;
		} while (N<0);

	}
    system("PAUSE"); return 0;

}
