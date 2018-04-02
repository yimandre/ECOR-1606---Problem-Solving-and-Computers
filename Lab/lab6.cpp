// LAb 6: Mock Midterm Review
// This program is used to determine the retirement income of an individual set by his/her intial value and over a specific amount of time
// Name: Andre Yim
// Student Number: 100961929

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

    // INSERT YOUR CONSTANT DECLARATIONS HERE
    
    // INSERT YOUR VARIABLE DECLARATIONS HERE
    double X; //dollars in bank
    double I; //Interest %
    double N; //life expectancy in years
    double x;
    double y;
    double income; //result
    double incomeavg; //avgerage income
    double i; // I/100
    double P; //starter
    double greatest; //greatest annual income
    
            
    // INSERT YOUR STATEMENTS HERE
    
    cout << "Enter 1 to start program: ";
    cin >> P;
    
    greatest = 0;
    
    while (P == 1) {
    	if (P == 1) {
	    	cout << "Enter Interest rate (-1 to exit): ";
    		cin >> I; 
	    	while (I<0 || I>10) {
 	   			if (I = -1) {
					return 0;
				}else {
 		   			cout << " Input values are unreasonable" << endl;
 		   			cout << " Enter Interest Rate: ";
					cin >> I;
				} //endif
 	   		} //endwhile
			i= I/100.0;
    
			cout << "Now enter years expected (-1 to exit): ";
			cin >> N;
			while (N<5) {
    			if (N = -1); {
    				return 0;
			} //endif
			cout << " Input values are unreasonable" << endl;
    		cout << " Enter Years expected: ";
			cin >> N; 
   			} //endwhile
		   
			cout << "Please Enter Initial Amount of Money (-1 to exit): ";
			cin >> X;
    		while(X < 0) {
    			if (X = -1) {
    				return 0;
    			}else if (X < -1) {
    				cout << "Input values are unreasonable" << endl;
    				cout << "Enter Initial Amount of Money: ";
    				cin >> X;
				} //endif
			} //endwhile
    	x = i*(pow((1+i) , (N-1)));
   		y = (pow((1 + i) , N) - 1);
    	income = X*(x/y) + X;
    
    	incomeavg = income / N;

    	
    	if (incomeavg > greatest) {
    		greatest = incomeavg;
    	} else {
    		incomeavg = incomeavg + 0;
    	} //endif
    	cout << "The net income for " << N << " with an interest of " << I << "% will be " << income << endl;
    	cout << "The average income is " << incomeavg << endl;
    	cout << "The greatest annual income is" << greatest << endl;
    	
    
    	} else if (P != 1) {
    		return 0;
    	} //endif
    	
    	} //endwhile

    
    
	 	
    system("PAUSE"); return 0;

}
