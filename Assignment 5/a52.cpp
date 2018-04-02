/* Author:       Andre Yim
   Subject:      ECOR 1606
   Assignment#5, Question #2
   Purpose:      This program allows the user to enter the location of two airports,
                 and a wind direction in degrees true.  The program does the necessary 
                 unit convertions to determine which way an aircraft should take off & fly.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
bool inputPosition( bool isDestination,double &lat, double &lng ){
	double lat1, lng1, lat2, lng2;
	if (isDestination) {
		for (;;) {	
			cout << "Please enter lat and long of the destination: ";
			cin >> lat2 >> lng2;
	
			if ( lat2 < -90 || lat2 > 90) {
				cout << "latitude must be between -90 and 90 degrees";
			}
			else if (lng2 < -180 || lng2 > 180) {
				cout << "longitude must be between  -180 and 180 degrees";
			}
			else {
				lat = lat2;
				lng = lng2;
				break;
			}		
			cout << endl << endl;
		}
	} else {
		for (;;) {
			cout << "Please enter lat and long of 1st point: ";
			cin >> lat1 >> lng1;
			
			if ( lat1 < -90 || lat1 > 90) {
				cout << "latitude must be between -90 and 90 degrees";
				}
			else if (lng1 < -180 || lng1 > 180) {
				cout << "longitude must be between  -180 and 180 degrees";
			}
			else {
				lat = lat1;
				lng = lng1;
				break;
			}
			cout << endl << endl;
		}
	}	
}
	
double calcDistanceDegrees( double lat1, double lng1,double lat2, double lng2) {
	double deltaLng,
		   deltaX,
		   deltaY,
		   course,
		   cosAngularDistance,
		   angularDistance;
	const double EARTH_CIRCUMFRENCE = 360  * 60;
	const double EARTH_RADIUS = 6377.707,
				 RADS_PER_DEG = M_PI/180.0,
				 DEGS_PER_RAD = 1/RADS_PER_DEG;
				 lat1 *= RADS_PER_DEG;
				 lng1 *= RADS_PER_DEG;
				 lat2 *= RADS_PER_DEG;
				 lng2 *= RADS_PER_DEG;
	deltaLng = lng1 - lng2;
	deltaY = sin(deltaLng)*cos(lat2);
	deltaX = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltaLng);
	course = atan2( deltaY, deltaX );
	return course;
}


double calcCourseDegrees( double lat1, double lng1,double lat2, double lng2){
	
	double deltaLng,
		   course,
		   distance,
		   cosAngularDistance,
		   angularDistance,
		   degrees;
	const double EARTH_CIRCUMFRENCE = 360  * 60;
	const double EARTH_RADIUS = 6377.707,
				 RADS_PER_DEG = M_PI/180.0,
				 DEGS_PER_RAD = 1/RADS_PER_DEG;
				 lat1 *= RADS_PER_DEG;
				 lng1 *= RADS_PER_DEG;
				 lat2 *= RADS_PER_DEG;
				 lng2 *= RADS_PER_DEG;
		
	if ( course < 0 ) course += 2*M_PI;
	course *= DEGS_PER_RAD;
	
	cosAngularDistance =  ( ( cos (lat1) * cos (lat2) * cos (fabs(deltaLng)) ) +( sin (lat1) * sin (lat2) ) );
	angularDistance = acos (cosAngularDistance);
	
	    cout << setiosflags (ios::showpoint | ios::fixed) << setprecision (2);
    	cout << endl;
		cout << "The airports are " << EARTH_RADIUS * angularDistance << " km apart" 
		 << "In direction: " << course << ". (degrees True)" 
         << endl << endl ;

	// convert to degrees magnetic
	course += 14;
	while (course > 360) {
		course -= 360;
	}
	
	return distance;
}
int selectRunway( double windDir, int rw_dir ) {
	double wVel,
		   wDir,
		   deltaAngle,
		   course,
		   RADS_PER_DEG,
		   DEGS_PER_RAD,
		   wca,
		   gs;
	const int airspeed = 100,
	          runway1 = 12;
	
	
	for (;;) { // sentinal loop
	
		for (;;) { // Valid input check
		    cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
		    cout << "    or 0 and 0 to exit ";
		    cin >> wVel >> wDir;
		
			if (wVel < 0) {
				cout << "The wind must be a positive number: " << endl;
			}
			else if (wDir  < 0 || wDir  > 360) {
	            cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
			}
			else {
				break;
			}		
		}
			
	    if ( wVel == 0 && wDir==0 ) {
	    	break;
		}
		
		if ( wVel > airspeed*0.40 ) {
			cout << "The wind is too strong.  Best not fly in these conditiosn" << endl;
		} else {
			// Convert the wind direction from True Headings to Magnetic
			wDir += 14;    // Note that the +14 is valid for Ottawa
                                   //      not everywhere on the globe
 
			if (wDir  < ( runway1*10 + 90 ) && wDir  > (runway1*10 - 90)) {
				cout << runway1;
			} else {
				cout << 18 + runway1;
			} // end if
		    cout << " is the preferred runway." << endl;
	 
			deltaAngle =  (wDir - course)*RADS_PER_DEG;   // difference in radians
			wca = asin( sin(deltaAngle) * wVel/airspeed );  // in radians
			gs = sqrt( airspeed*airspeed + wVel*wVel - 2*airspeed*wVel*cos( deltaAngle - wca ));
			cout << "The plane needs to fly into the wind by: " << wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "  It's heading would be: " << course + wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "  It's ground speed would be: " << gs << " knots." << endl;
			cout << endl;
		}
	} // end sentinel loopwhile(wVel != 0 && wDir!=0)
}
int main (void) {
	double 	   lat1,lat2,lng1,lng2;
	double     distance, course;
	double	   windDir;
	int 	   rW_dir = 120;
	const double EARTH_RADIUS = 6377.707;
	
	bool destination = false;
		   
	inputPosition (destination, lat2, lng2);
	destination = true;
	inputPosition (destination, lat1, lng1);

	distance = calcDistanceDegrees (lat1,lng1,lat2,lng2);

	calcCourseDegrees(lat1,lng1,lat2,lng2);

	selectRunway(windDir,rW_dir);
	
	
    system("PAUSE"); return 0;
}
