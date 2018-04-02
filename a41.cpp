/* Author:       Prof. B. Chawla
   Subject:      ECOR 1606
   Assignment#3, Question #2
   Purpose:     You are given a certain amount of money, and you are tasked with 
                    buying the most expensive drink, and food available 
					with that amount.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main (void) {
    // Variables
    double aDrink, aFood,      // Will hold the amount of money available
           costDrink, costFood,
		   mostExpensiveMeal;
	double a; 
	int calFood,
		calDrink,
		vcFood,
		vcDrink,
		leastCalories,
		greatestVC,
		totalVC = 0,
		cal650Count = 0,
		mealCount = 0;
		
	
//Initial input
	cout << "Enter total amount of money you wish to spend: ";
	cin >> a;
	
	while (a<0 || a >35) {
		if (a < 0) {
			cout << "Error: Spending must be a positive number." << endl;
			cout << "Please enter positive number: " ;
			cin >> a;			
		} if (a > 35) {
			cout << "Please keep spending under $35." << endl;
			cout << "Enter a total spending: ";
			cin >> a;
		} //endif
	} //endwhile
	
// Now loop as long as the sentinal value is not input ( 0, 0 ).
        double maxCo = 0, lowPrice = a;
	aDrink = a;
	while ( !(aFood == 0 && aDrink == 0)) {
			  
	    if (aFood >= 0) {
	        // Process valid money amounts
	        if (aFood >= 24) {
	            //cout << "We recommend you purchase Steak & Broccoli, for $24.00";
	            costFood = 24;
		    calFood = 300;
	            vcFood  = 148;
	        } else if (aFood >= 14.99) {
	            //cout << "We recommend you purchase an Veggie Platter, for $14.99";
	            costFood = 14.99;
	    	    calFood = 80;
	            vcFood  = 30;
	        } else if (aFood >= 6.75) {
	            //cout << "We recommend you purchase an Submarine Sandwich, for $6.75";
	            costFood = 6.75;
	            calFood = 200;
	            vcFood  = 9;
	        } else if (aFood >= 3.50) {
	            //cout << "We recommend you purchase a Pepperoni Pizza, for $3.50";
	            costFood = 3.50;
	            calFood = 250;
	            vcFood  = 6;
	        } else if (aFood >= 2.50) {
	            //cout << "We recommend you purchase an all dressed Hamburger, for $2.50";
	            costFood = 2.50;
	            calFood = 301;
	            vcFood  = 12;
	        } else if (aFood >= 1.00) {
	            //cout << "We recommend you purchase a Doughnuts, for $1.00";
	            costFood = 1;
	            calFood = 452;
	            vcFood  = 2;
	        } else if (aFood >= 0.35) {
	            costFood = 0.35;
	            calFood = 436;
	            vcFood  = 0;
	            //cout << "We recommend you purchase a Noodle soup, for $0.35";
	        } else {
	            costFood = calFood = vcFood  = 0;
	            //cout << "You cannot afford any food";
	        } // end ifMax Food: 134516274
	
	    } // end if
	    // Go through the list of possible drinks
	    // From most expensive to least
	    if (aDrink>=0) {
	        // Process valid money amounts
	        if (aDrink >= 8.99) {
	            //cout << "We recommend you purchase an OJ with Carrots & Spinach, for $8.99";
	            costDrink = 8.99;
	            calDrink = 101;
	            vcDrink  = 236;
	        } else if (aDrink >= 4.99) {
	            //cout << "We recommend you purchase an OJ, for $4.99";
	            costDrink = 4.99;
	            calDrink = 112;
	            vcDrink  = 207;
	        } else if (aDrink >= 3.50) {
	            //cout << "We recommend you purchase an Asparagus Milkshake, for $3.50";
	            costDrink = 3.50;
	            calDrink = 203;
	            vcDrink  = 50;
	        } else if (aDrink >= 2.50) {
	            //cout << "We recommend you purchase a Strawberry Milkshake, for $2.50";
	            costDrink = 2.50;
	            calDrink = 250;
	            vcDrink  = 149;
	        } else if (aDrink >= 1.75) {
	            //cout << "We recommend you purchase a Tea, for $1.75";
	            costDrink = 1.75;
	            calDrink = 2;
	            vcDrink  = 7;
	        } else if (aDrink >= 1.25) {
	            //cout << "We recommend you purchase a Water, for $1.25";
	            costDrink = 1.25;
	            calDrink = 0;
	            vcDrink  = 0;
	        } else if (aDrink >= 0.95) {
	            //cout << "We recommend you purchase a Coffee, for $0.95";
	            costDrink = 0.95;
	            calDrink = 0;
	            vcDrink  = 0;
	        } else if (aDrink >= 0.25) {
	            //cout << "You could purchase a Pop, for $0.25";
	            costDrink = 0.25;
	            calDrink = 160;
	            vcDrink  = 0;
	        } else {
	            //cout << "You cannot afford any drink";
	            costDrink = calDrink = vcDrink  = 0;
	        } // end if selecting the most expensive meal
	    } // endif
	    if (vcDrink+vcFood > maxCo){     
	    	cout << "This meal would cost $" << costFood+costDrink
				<< ", with " << calFood+calDrink 
				<< " Calories and " << vcFood+vcDrink 
				<< "% of the daily required Vitamin C" << endl;
           
	    }
	    
		// Gather statistics
		if (costFood+costDrink > 0) {
			mealCount++;
	
			if ( mealCount == 1 || mostExpensiveMeal < (costFood+costDrink) ) {
				mostExpensiveMeal = costFood+costDrink;
			}
			if ( mealCount == 1 || leastCalories > (calFood+calDrink)) {
				leastCalories = calFood+calDrink;
			}
			totalVC += vcFood + vcDrink;
			if ( mealCount == 1 || greatestVC < (vcFood+vcDrink)/(costFood+costDrink) )  {
				greatestVC = (vcFood+vcDrink)/(costFood+costDrink);
			}
			if ( calFood+calDrink > 650) {
				cal650Count++;
			}
			
		}
	
		//aDrink = a;
		aDrink -=0.05;
		aFood +=0.05;
		// manual to control the rate of food and drink.
		do {		
		    cout << "Please total amount of money you wish to spend: ";
		    cin >> a;
			if ( a < 0) {
				cout << "Error: Amount must be positive" << endl;
			}
			if ( a > 35) {
				cout << "Error:Amount must be under $35.00" << endl;
			}
			break;
			
		} while ( a< 0 || a > 35);
	}

	// End of sentinal loop.
	if (mealCount > 0) {
		cout <<	"The most expensive meal costs: $" << mostExpensiveMeal 
			  << endl;
		cout << "The meal with the least calories had: " 
			 << leastCalories << " calories"
			  << endl;
		cout << "The average vitamin C per meal was: " << totalVC/mealCount
		      << endl;
		cout << "The most econmical source of 'C' was: " << greatestVC << "%/dollar"
		      << endl;
		cout << 100*cal650Count/mealCount << "% of the meals had more than 650 calories."
			  << endl;
	}
    //system("PAUSE"); 
    return 0;
}
