#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

double computePressure(double &d, double &delta, double thickness) {
	double p,b,c, testp, desiredP, bestThickness;
	double bestp = 9999;
	double bestThick;
	double const E = 207e9,
				 v = 0.28;
	double top, bottom, bottom2;
	
	cout << "Enter hub diameter and interference: " ;
	cin >> d >> delta;
	
	while (d < 0 || delta < 0) {
		if (d < 0.5 || d > 2.5) {
			cout << "Invalid values ignored" << endl;
			cout << "Enter hub diameter and interference: " ;
			cin >> d >> delta;
		} else if (delta < 0 || delta > 0.005*d) {
			cout << "Invalid values ignored" << endl;
			cout << "Enter hub diameter and interference: " ;
			cin >> d >> delta;
		} else {
			break;
		}
	}


	
	cout << "Thickness(cm)" << setw(15) << "Pressure(MPA)" << endl;
	cout << "---------------------------" << endl;
	
	for (thickness = 6.0 ; thickness < 12.5; thickness += 0.5 ) {
		b = d/2;
		c = b + (thickness*0.01); 
	
		top = (delta/(b));
		bottom = (1/E)*(((pow(c,2)+pow(b,2))/(pow(c,2)-pow(b,2)))+v);
		bottom2 = (1/E)*(1-v);
		
		p = top/(bottom + bottom2);
		p *= 10e-7;
		 
		cout << setw(4) << thickness << setw(20) << p << endl;
		
		testp = fabs(20 - p);
		
		if (testp > 5) {
			cout << "All of the tire thickness are unacceptable.";
		} else if (testp < bestp) {
			bestp = testp;
			bestThickness = thickness;
			desiredP = p;
		}

	}
	cout << "The tire thickness of " << bestThickness << " cm comes to closest to giving a pressure of " << desiredP << endl;
	
	return p;
}


int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
    double d, delta, thickness;
            
    // INSERT YOUR STATEMENTS HERE
    
	do {
		computePressure(d,delta,thickness);
	} while (delta != 0 || d != 0);

    

    system("PAUSE"); return 0;

}
