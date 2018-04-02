// This program will take the Sine Integral function and output
// some shit out
// Name: Andre Yim
// Student Number: 100961929

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

double Si (int a,int b, int N) {
	double result;
	double const A0 = 2.5253303767,
				 A1 = 1.0370462484,
				 A2 = 0.5688888889,
				 A3 = 0.3111070642,
				 A4 = 0.1242940878;
				 
	double const T0 = 0.0469100770,
				 T1 = 0.2307653450,
				 T2 = 0.5000000000,
				 T3 = 0.7692346550,
				 T4 = 0.9540899230;
				 
	
	int x;
	
	cout << "Please enter a, b and N values: ";
	cin >> a >> b >>N;
	
	while (a == 0 || b == 0 || N == 0) {
		break;
	}
	
	while (a > b) {
		cout << "*** Invalid input -- try again**" << endl;
		cout << "Please enter a, b, and N values: ";
		cin >> a >> b >> N;
		
		while (a < 0 || b < 0) {
			cout << "*** Invalid input -- try again**" << endl;
			cout << "Please enter a, b, and N values: ";
			cin >> a >> b >> N;
		}
	}
	
	double high, low = 0;
		low = A0*sin(a*T0) + A1*sin(a*T1) + A2*sin(a*T2) + A3*sin(a*T4) +  A4*sin(a*T4);
		high = A0*sin(b*T0) + A1*sin(b*T1) + A2*sin(b*T2) + A3*sin(b*T4) +  A4*sin(b*T4));
		
		cout << "The "
	return result;
}


int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
    double a,b;
    int N;

            
    // INSERT YOUR STATEMENTS HERE

	Si(a,b,N);
    

    

    system("PAUSE"); return 0;

}
