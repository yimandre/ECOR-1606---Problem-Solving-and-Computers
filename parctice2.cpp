// This program has something to do with air compression and incidentt/angle of a blade
//
// Name: Andre Yim
// Student Number: 100961929

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

double computeBladeExitAngle (double alpha1,double beta2, double &s) {
	
	int incidence;
	double beta1, alpha2;
	double top, bottom;
	double bestS = s;
	
	
	top = beta2 -alpha1*(0.23 + (beta2/500))*(pow((1/bestS),0.5));
	bottom = 1 -(0.23+(beta2/500))*(pow((1/bestS),0.5));
	alpha2 = top/bottom;
	
	cout << "Blade exit angle: " << alpha2 << endl;
	return alpha2;
}


double computeSolidity (double beta1, double beta2) {
	double incidence, s, alpha2;
	double bestS;
	double LHS,TLHS;
	double PLHS = 999;
	double alpha1;
	double top, bottom;
	double test;
	
	cout << "Please enter flow entry angle, flow exit angle and incidence: ";
	cin >> beta1 >> beta2 >> incidence;
	test = (36- 0.45*beta2) / (beta1 - beta2);
	
	while ( beta1 == -1 ||  beta2 == -1 || incidence == -1){
		break;
	}
	
	if (beta2 < -10 || beta2 > 50) {
		cout << "Invalid values ignored." << endl;
		cout << "Please enter flow entry angle, flow exit angle and incidence: ";
		cin >> beta1 >> beta2 >> incidence;
	} else if (test < 0.75 || test > 1.25) {
		cout << "Invalid values ignored." << endl;
		cout << "Please enter flow entry angle, flow exit angle and incidence: ";
		cin >> beta1 >> beta2 >> incidence;
	} else if (incidence < -3 || incidence > 3){
		cout << "Invalid values ignored." << endl;			cout << "Please enter flow entry angle, flow exit angle and incidence: ";
		cin >> beta1 >> beta2 >> incidence;
	}
	
	
	cout << "Solidity" << setw(10) << "LHS" << endl;
	cout << "________________________" << endl;

	
	for (double s = 0.6; s < 2.2; s+=0.1) {
		
		alpha1 = beta1 - incidence;
		
		LHS = 33.5291 + (0.49188+0.0020961*beta2)*beta2 - beta1 + (187148*beta2 - 15.2599)*log(1/s) - 0.677212*pow(log(1/s), 2);
		cout << s;
		cout << setw(15) << LHS << endl;

		while (fabs(LHS) < PLHS) {
			if (fabs(LHS) < PLHS) {
				PLHS = fabs(LHS);
				bestS = s;
			} else {
				break;
			}
		}
		
	}
	cout << endl;
	cout << "Leaving Function. The chosen value is " << bestS << endl;
	cout << endl << "Blade entry angle: " << alpha1 << endl;
	cout << "Solidity: " << bestS << endl;
	computeBladeExitAngle (alpha1,beta2, bestS);
	
	
	return s;
}



int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
    double s,b, incidence,
    	   beta1, beta2,
    	   alpha1;
    // INSERT YOUR STATEMENTS HERE
	
	
	
	for (;;) {
		computeSolidity(beta1,beta2);
	}
   

    system("PAUSE"); return 0;

}
