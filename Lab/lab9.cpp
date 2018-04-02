// This program will allow the user to calculate the pressure drop inside a pipe which is depenedent on the diameter
//
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

// This function calculates and returns the friction factor using
// successive approximations to an accuracy of 0.000001.  
// The parameters are:
// R - Reynolds number
// D - diameter (in metres)
// epsilon - roughness (in metres)
double calcFrictionFactor(double R, double D, double epsilon) 
{
    const double BlasiusCoefficient = 0.3164;
    double f_old, f_new;

    f_new =  BlasiusCoefficient * pow(R, -0.25);

	// loop until our two values are within 0.000001 of each other
    do {
		  f_old = f_new; // previous guess is now the old one
		  
	      // plug guess into the right hand side of the ColeBrook formula
	      f_new = 0.25 * pow(log10((epsilon/D)/3.7 + 2.51 / (R*sqrt(f_old))), -2);

    } while (fabs(f_new - f_old) > 0.000001);

    return f_new;
}


double calcReynolds (double rho, double V, double D, double mu) {
	double R, a, b;
	a = (rho * V * D);
	b = mu;
	
	R = a/b;
	return R;
}


double calcPressureLoss (double V, double L, double D, double rho, double mu, double epsilon) {
	double delta, R;
	double a,b,c,d;
	
	R = calcReynolds(rho, V, D, mu);
	a = calcFrictionFactor(R ,D ,epsilon);
	b = L / D;
	c = rho;
	d = V*V/ 2.0;
		
	delta = (a*b) * (c*d);
	return delta;
}

void printTable (double V, double L, double rho, double mu, double epsilon, double D) {
	double x;
	double calc;
	int i;
	
	cout << setiosflags (ios::fixed | ios::showpoint) << endl;
	cout << "Diameter (m)			Pressure Drop (Pa)" << endl;
	cout << "---------------------------------------------" << endl;
	for (i=0; i<15 ; i++) {
		x = (i+1)*0.05;
		calc = calcPressureLoss(V,L,x,rho,mu,epsilon);
		cout << setprecision (2) << setw(12) << x;
		cout << setprecision(1) << setw(24) << calc << endl;
		
	}
}


int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE
    const double rho = 998.2;
    const double mu= 0.001002;
    const double epsilon = 0.000045;

    // INSERT YOUR VARIABLE DECLARATIONS HERE
	double V, D, L; 
    // INSERT YOUR STATEMENTS HERE
    
    
    do {
    	cout << "Enter flow velocity and distance (-1,-1 to exit): ";
    	cin >> V >> L;
    	printTable (V,L,rho,mu,epsilon,D); 
    	
    	if (V == -1 && L == -1) {
    		return 0; 
    	}
    } while (V != -1 && L != -1);
    
    
    

    

    system("PAUSE"); return 0;

}
