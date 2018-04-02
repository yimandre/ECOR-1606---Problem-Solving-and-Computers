/* Author:       Prof. B. Chawla
   Subject:      ECOR 1606
   Assignment#3, Question #1
   Purpose:      This program allows the user to enter a wind direction in degrees true, 
                 converts the value to a �compass wind direction� to determine which way 
                 an aircraft should fly, and then land.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;


int main (void) {
// Constants
    const int runway1 = 12;   // Runway option
    const double airspeed = 100,
                 course = 140;

// Variables
    double  wDir, 
            wVel,
            deltaAngle,
            wca,  // wind correction angle
            gs;   // ground speed

   const double EARTH_RADIUS = 6377.707, //in km
   					RADS_PER_DEG = M_PI/180.0;

//obtain input information
//lat and long are in degrees

	cout << "Please enter lat and long of 1st airport: ";
	cin >> lat1 >> lng1;
	cout << "Please enter lat and long of 2nd airport: ";
	cin >> lat2 >> lng2;
	
	lat1 = lat1 * RAD_PER_DEG;
	lng1 = lng1 * RAD_PER_DEG;
	lat2 = lat2 * RAD_PER_DEG;
	lng2 = lng2 * RAD_PER_DEG;
	
//compute the difference in longitude
	deltaLng = lng1 - lng2;
	deltaY = sin(deltaLng)*cos(lat2);
	deltaX = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(delatLng);
	course = atan2(deltaY,deltaX);
	
	if (course < 0) course += 2*M_PI; //add 360deg, or 2*3.1415..
	
//apply the distance formula from Chapter 2
	cosAngularDistance = ((cos(lat1) * cos(lat2) * cos(fabs(deltaLng)))) + (sin(lat1) * (sin(lat2)));
	angularDistance = acos (cosAngularDistance);
	distance = EARTH_RADIUS* angularDistance;
	
	cout << "The points are" << distance << " km apart"
		 << "In direction: " << course/RADS_PER_DEG << "." << endl;
   
   
   
   
   
   
   
   /* // Constants
    const int runway1 = 12;   // Runway option
    const double airspeed = 100,
                 course = 140;

    // Variables
    double  wDir, 
            wVel,
            deltaAngle,
            wca,  // wind correction angle
            gs;   // ground speed
            
    cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
    cout << "    or 0 and 0 to exit ";
    cin >> wVel >> wDir;

	while (wVel<0 || wDir  < 0 || wDir  > 360 ){
		if (wVel < 0) {
			cout << "The wind must be a positive number: " << endl;
		}
		if (wDir  < 0 || wDir  > 360) {
            cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
		}
		cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
    	cout << "    or 0 and 0 to exit ";
    	cin >> wVel >> wDir;

	}

    while ( wVel != 0 || wDir!=0) {

		if ( wVel > airspeed*0.40 ) {
			cout << "The wind is too strong.  Best not fly in these conditiosn" << endl;
		} else {
			// Convert the wind direction from True Headings to Magnetic
			wDir  = wDir  + 14;    // Note that the +14 is valid for Ottawa
                                   //      not everywhere on the globe
 
			if (wDir  < ( runway1*10 + 90 ) && wDir  > (runway1*10 - 90)) {
				cout << runway1;
			} else {
				cout << 18 + runway1;
			} // end if
			cout << " is the preferred runway." << endl;

			
			deltaAngle =  (wDir - course)*M_PI/180;   // difference in radians
			wca = asin( sin(deltaAngle) * wVel/airspeed );  // in radians
			gs = sqrt( airspeed*airspeed + wVel*wVel - 2*airspeed*wVel*cos( deltaAngle - wca ));

			cout << "The plane needs to fly into the wind by: " << wca*180/M_PI << "degrees." << endl;
			cout << "  It's heading would be: " << course + wca*180/M_PI << " degrees." << endl;
			cout << "  It's ground speed would be: " << gs << " knots." << endl;
		}

        // Ask user for the next set of inputs
	    cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
	    cout << "    or 0 and 0 to exit ";
	    cin >> wVel >> wDir;

		while (wVel<0 || wDir  < 0 || wDir  > 360 ){
			if (wVel < 0) {
				cout << "The wind must be a positive number: " << endl;
			}
			if (wDir  < 0 || wDir  > 360) {
	            cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
			}
			cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
	    	cout << "    or 0 and 0 to exit ";
	    	cin >> wVel >> wDir;
		} // end while(inputs are invalid)
	} // end sentinel loopwhile(wVel != 0 && wDir!=0)
    system("PAUSE"); return 0;
}
