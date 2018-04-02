// Assignment 3, Part 1
// This program will alow the user to enter a wind direction and velocity.
// Depending on the value enter, it will tell determine the angle needed to correct the flight path
// Name:Andre Yim
// Student Number:100961929


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
    double const course = 140;
    double const tAS = 100;
    double const runway1 = 12;
    double const pi = 3.14;
    
    // Variables
    double wDir;
    double wVel;
    double WCA;
    double GS;
    double heading;
    

    cout << "Please enter wind velocity (in knots) and wind direction (in degrees True)or 0 0 to exit: ";
    cin >> wDir >> wVel;
    
    while (wDir != 0 && wVel != 0) {
    	
    	if (wDir < 0 && wDir > 360) {
			cout << "Sorry: " << wDir << " is no a valid angle." << endl;
			return 0;
		} //endif
		
		if (wDir >= 0 && wDir <= 360) {
			wDir = wDir + 14;
		} if (wDir < ( runway1*10 + 90 ) && wDir > (runway1*10 - 90)) {
        	cout << "Runway "<< runway1 << "is perferred." << endl;
        } else {
            cout << "Runway " << 18 + runway1 << "is perferred" <<endl;
        }if (wDir < 0 && wDir > 360) {
		cout << "Sorry: " << wDir << " is no a valid angle." << endl;
		return 0;
		} //endif
		
		if (wVel> 40 || wVel < 0) {
			cout << "Warning : It is unsafe to fly and that Wind Velocity is not negative.";
		} else {
			course == course*(180/pi);
			WCA = asin(sin(wDir - course)*wVel/tAS);
			heading = course + WCA;
			WCA = WCA - 14;
			wDir = wDir*(180/pi);
     		WCA = (180/pi);
			cout << "The wind correction for this aircraft is " << heading  << " degress."<< endl;
			GS = sqrt((pow(tAS,2)+ pow(wVel,2)) - (2*tAS*wVel*cos(wDir - course - WCA)));
			cout << "The Ground speed is " << GS  << " knots."<< endl;
		}//endif
		
		cout << "Please enter wind velocity (in knots) and wind direction (in degrees True)or 0 0 to exit: ";
    	cin >> wDir >> wVel;
	} //end while
    

    system("PAUSE"); return 0;

}
