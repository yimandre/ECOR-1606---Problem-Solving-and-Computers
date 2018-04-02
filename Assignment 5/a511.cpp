/* Author:       Prof. B. Chawla
   Subject:      ECOR 1606
   Assignment#4, Question #1
   Purpose:      You are given a certain amount of money, and you are tasked with 
                    buying the meal wigh most Vitamin C with that amount.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;


double getMaxDollars( void ) {
	double amount;
	
	cout << "Please enter the total amount of money you wish to spend on Food and Drink: ";
	cin >> amount;

	while (amount > 35 || amount < -1) {
		if (amount < 0) {
			cout << "The amount entered is invalid" << endl;
			cout << "Please enter the total amount of money you wish to spend on Food and Drink: ";
			cin >> amount;
		} else if (amount > 35) {
			cout << "The amount entered is too large, please spend less." << endl;
			cout << "Please enter the total amount of money you wish to spend on Food and Drink: ";
			cin >> amount;
		} //endif
	}
	return amount;
}


bool fequals( double a , double b ){
	if (fabs(b-a) < 0.0001) {
		return true;
	}
	return false;
}

double selectFood( double amount, int &vcFood, int &calFood ) {
	double costFood, costDrink,
		   aFood;
	int vcDrink, calDrink;
	
	 if (aFood >= 24) {
            costFood = 24.00;
			calFood = 300;
            vcFood  = 148;
        } else if (aFood >= 14.99) {
            costFood = 14.99;
            calFood = 80;
            vcFood  = 30;
        } else if (aFood >= 6.75) {
            costFood = 6.75;
            calFood = 200;
            vcFood  = 9;
        } else if (aFood >= 3.50) {
            costFood = 3.50;
            calFood = 250;
            vcFood  = 6;
        } else if (aFood >= 2.50) {
            costFood = 2.50;
            calFood = 301;
            vcFood  = 12;
        } else if (aFood >= 1.00) {
            costFood = 1;
            calFood = 452;
            vcFood  = 2;
        } else if (aFood >= 0.35) {
            costFood = 0.35;
            calFood = 436;
            vcFood  = 0;
        } else {
            costFood = calFood = vcFood  = 0;
        } // end if
        return costFood;
}


double selectDrink( double amount, int &vcDrink, int &calDrink ) { 
	double costDrink,
		   aDrink;
	
	if (aDrink >= 8.99) {
            costDrink = 8.99;
            calDrink = 101;
            vcDrink  = 236;
        } else if (aDrink >= 4.99) {
            costDrink = 4.99;
            calDrink = 112;
            vcDrink  = 207;
        } else if (aDrink >= 3.50) {
            costDrink = 3.50;
            calDrink = 203;
            vcDrink  = 50;
        } else if (aDrink >= 2.50) {
            costDrink = 2.50;
            calDrink = 250;
            vcDrink  = 149;
        } else if (aDrink >= 1.75) {
            costDrink = 1.75;
            calDrink = 2;
            vcDrink  = 7;
        } else if (aDrink >= 1.25) {
            costDrink = 1.25;
            calDrink = 0;
            vcDrink  = 0;
        } else if (aDrink >= 0.95) {
            costDrink = 0.95;
            calDrink = 0;
            vcDrink  = 0;
        } else if (aDrink >= 0.25) {
            costDrink = 0.25;
            calDrink = 160;
            vcDrink  = 0;
        } else {
            costDrink = calDrink = vcDrink  = 0;
        } // end if selecting the most expensive meal
        return costDrink;
}



// Prints the name of the drink selected, for a given dollar value.
// This function should use the fequals() function defined above
// The function only prints the food (e.g. "a Strawberry Milkshake")
// so that the same function can be used in a table and elsewhere.
void printDrink( double amount ) {
if ( fequals( amount, 8.99)) {
cout << "OJ with Carrots & Spinach";
} else if ( fequals( amount, 4.99)) {
cout << "an OJ";
} else if ( fequals( amount, 3.50)) {
cout << "an Asparagus Milkshake";
} else if ( fequals( amount, 2.50)) {
cout << "a Strawberry Milkshake";
} else if ( fequals( amount, 1.75)) {
cout << "a Tea";
} else if ( fequals( amount, 1.25)) {
cout << "a Water";
} else if ( fequals( amount, 0.95)) {
cout << "a Coffee";
} else if ( fequals( amount, 0.25)) {
cout << "a Pop";
} else {
cout << "no drink";
} // end if selecting the most expensive meal
}
// Prints the name of the food selected, for a given dollar value.
// This function uses the fequals() function defined above
// The function should only print the food (e.g. "a Hamburger")
// so that the same function can be used in a table or
// as in an output string.
void printFood( double amount ) {
if ( fequals( amount, 24.00 ) ) {
cout << "Steak & Broccoli";
} else if ( fequals( amount, 14.99)) {
cout << "a Veggie Platter";
} else if ( fequals( amount, 6.75)) {
cout << "a Submarine Sandwich";
} else if ( fequals( amount, 3.50)) {
cout << "a Pepperoni Pizza";
} else if ( fequals( amount, 2.50)) {
cout << "an all dressed Hamburger";
} else if ( fequals( amount, 1.00)) {
cout << "a Doughnut";
} else if ( fequals( amount, 0.35)) {
cout << "a Noodle soup";
} else {
cout << "no food";
} // end if
}

int main (void) {

    // Variables
    double amount, aDrink, aFood,      // Will hold the amount of money available
           costDrink, costFood,
		   mostExpensiveMeal,
           bestVC,                     // The meal combination with the most vitamin C
           bestComboFood, 
           bestComboDrink;
           
	int calFood,
		calDrink,
		vcFood,
		vcDrink,
		leastCalories,
		greatestVC,
		totalVC = 0,
		cal650Count = 0,
		mealCount = 0,
		iFor,
		iMax;
		
		do {
			amount = getMaxDollars();
			
		
			if ( amount == 0 ) {
	        	break;
	    	}
			iMax=int(amount/0.05 + 0.001);
// Now loop through all the possible values to determine the best meal
    		for ( iFor = 0 ; iFor <= iMax ; iFor++ ) {
    	    
    	    	aFood=iFor*0.05;
    	    	aDrink = amount - aFood;
    	    	
    	    	costFood = selectFood(amount, vcFood, calFood);
				costDrink = selectDrink (amount, vcDrink, calDrink);
    	    }
			

			
		} while ( amount !=-1);
/*
		
	
    	// Now Print the best solution:
    	aFood = bestComboFood;
    	aDrink = bestComboDrink;

        

        
		// Gather statistics
		if (costFood+costDrink > 0) {
	
		    cout << "This meal would cost $" << costFood+costDrink
					<< ", with " << calFood+calDrink 
					<< " Calories and " << vcFood+vcDrink 
					<< "% of the daily required Vitamin C" << endl;
		    cout << endl;
		    
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
		
	} // End of sentinal loop.

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
*/
    system("PAUSE"); return 0;

}

