/* Author:       Andre Yim
   Subject:      ECOR 1606
   Assignment#6, Question #2
   Purpose:      This program allows the user to enter the location of two airports,
                 and a wind direction in degrees true.  The program does the necessary 
                 unit convertions to determine which way an aircraft should take off & fly.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

	const double EARTH_RADIUS = 6377.707,  // in km
	             RADS_PER_DEG = M_PI/180.0,
	             DEGS_PER_RAD = 1/RADS_PER_DEG;


int selectRunway( double windDir, int rw_dir ){
	int runway = int(rw_dir+5)/10;
	if (windDir<(runway*10+90) && windDir>(runway*10-90)) {return runway; } 
	else { return 18 + runway; } // end if
}


bool inputPosition( bool isDestination, double &lat, double &lng ) {
    // obtain route information
	for (;;) {
		cout << "Please enter lat and long of ";
		if ( isDestination ) { cout << "Destination"; }
		else { cout << "Departure";  }
       		cout << " airport:";
		cin >> lat >> lng;
		if ( lat < -90 || lat > 90) { cout << "latitude must be between -90 and 90 degrees"; }
		else if (lng < -180 || lng > 180) { cout << "longitude must be between  -180 and 180 degrees"; }
		else { return !( lat==0 && lng==0 ); }
		cout << endl << endl;
	}    
}


double calcDistanceRadians( double lat1, double lng1, double lat2, double lng2){	
    double deltaLng, cosAngularDistance, angularDistance;	
    // compute the difference in longitude
    deltaLng = fabs (lng1 - lng2);
    // apply the distance formulae
    cosAngularDistance = ((cos(lat1)*cos(lat2)*cos(deltaLng))+(sin(lat1)*sin(lat2)));
    angularDistance = acos (cosAngularDistance);
    return EARTH_RADIUS * angularDistance;
}


double calcDistanceDegrees( double lat1, double lng1,  double lat2, double lng2){
    // convert input quantities to radians
    return calcDistanceRadians( lat1 * RADS_PER_DEG, lng1 * RADS_PER_DEG,
    				lat2 * RADS_PER_DEG, lng2 * RADS_PER_DEG);
}


double calcCourseDegrees( double lat1, double lng1, double lat2, double lng2)
{
    double deltaLng, deltaY, deltaX, course;

    // convert angles to radians
    lat1 *= RADS_PER_DEG;
    lng1 *= RADS_PER_DEG;
    lat2 *= RADS_PER_DEG;
    lng2 *= RADS_PER_DEG;
    // compute the difference in longitude
    deltaLng = lng1 - lng2;
    deltaY = sin(deltaLng)*cos(lat2);
    deltaX = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltaLng);
    course = atan2( deltaY, deltaX );

    if ( course < 0 ) course += 2*M_PI;
    // convert back to degrees
    course *= DEGS_PER_RAD;
    return course;
}

int displayAirports(double latitudes[], double longitudes[], int runways[], int maxAirports){

    ifstream fin;
    double value, total = 0;
    char str[255];
    int count =0;
    char fileName[] = "airports.txt";

    fin.open(fileName);
    if (fin.fail()){
        cout << "Unable to open the input file.\n";
	system("PAUSE");
	return 0; // stop propgram execution
    }

    cout << "Airport	" << "	Lat.	" << "	Long.	" << "	Runways" << endl;
    for (;;){
        fin >> str;

        if (fin.fail()){  break; }

	if (atof(str) != 0){
		if (count % 4 == 0) {latitudes[maxAirports] = atof(str); }
		else if (count % 4 == 1) { longitudes[maxAirports] = atof(str); }
		else { runways[maxAirports] = atoi(str); }
	} else { maxAirports++;}
	count++;
    }
    for(int i = 0; i < maxAirports; i++){
	cout << setw(5) <<  i+1  << setw(14) << setprecision(2)  << latitudes[i];
	cout << setw(15) << setprecision(2) << longitudes[i];
	cout << setw(20) << runways[i] << endl;
    }
    return 0;
}

int selectAirport ( bool isDestination, int maxN){
    // obtain route information
	for (;;) {
		if ( isDestination ) { cout << "Destination"; }
		else { cout << "Departure";  }
       		cout << " airport:";
		cout << "Please select an airport from 1 to " << maxN << ": " << endl;
		int airport = 0;
		cin >> airport;
		if (airport < 0 || airport > maxN){ return 0; }
		else { return airport; }
	}   
	return 0;
}


int main (void) {

    // Constants
    const int airspeed = 100, runway1 = 120;
    // Variables
    double  wDir, wVel, deltaAngle, 
	    wca,  // wind correction angle
            gs,   // ground speed
            lat1, lng1, lat2, lng2, distance, course;
    
	double latitudes[5];
	double longitudes[5];
	int runways[5];
	int maxAirports = 0;
    cout << "Display the information of the airport"<< endl;

    displayAirports(latitudes, longitudes, runways, maxAirports);


    // obtain route information
    if (inputPosition (false, lat1, lng1) && inputPosition(true, lat2, lng2)){       
        distance = calcDistanceDegrees( lat1, lng1, lat2,  lng2);
        course = calcCourseDegrees( lat1, lng1, lat2,  lng2);
        // Set the formatting to 2 decimal places    
        cout << setiosflags (ios::showpoint | ios::fixed) << setprecision (2);
        cout << endl;
        cout << "The airports are " << distance << " km apart" 
        	 << "In direction: " << course << ". (degrees True)" << endl << endl ;               
    } else { /* User entered 0, 0.  End the program*/ return 0; }

    // convert to degrees magnetic
    course += 14;
    if (course > 360) {
		course -= 360;
    }

    for (;;) { // sentinal loop
		for (;;) { // Valid input check
	   	 cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
	    	cout << "    or 0 and 0 to exit ";
	    	cin >> wVel >> wDir;	
			if (wVel < 0) { cout << "The wind must be a positive number: " << endl; }
			else if (wDir  < 0 || wDir  > 360) {  
				cout << "Sorry: " << wDir;
				cout <<" is not a valid angle.  Angles should be between 0 and 360 degrees."<< endl;
			} else { break; }		
		}
		if ( wVel == 0 && wDir==0 ) { break; }
		if ( wVel > airspeed*0.40 ) { cout << "The wind is too strong.  Best not fly in these conditiosn" << endl; } 
		else {
			// Convert the wind direction from True Headings to Magnetic
			wDir += 14;    // Note that the +14 is valid for Ottawa
                                  //      not everywhere on the globe
	    	cout << selectRunway( wDir, runway1 ) << " is the preferred runway." << endl;
			deltaAngle =  (wDir - course)*RADS_PER_DEG;   // difference in radians
			wca = asin( sin(deltaAngle) * wVel/airspeed );  // in radians
			gs = sqrt( airspeed*airspeed + wVel*wVel - 2*airspeed*wVel*cos( deltaAngle - wca ));

			cout << "The plane needs to fly into the wind by: " << wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "It's heading would be: " << course + wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "It's ground speed would be: " << gs << " knots." << endl;
			cout << endl;
		}
    }
	
    system("PAUSE"); return 0;
}
