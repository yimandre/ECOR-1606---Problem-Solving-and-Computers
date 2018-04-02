/* Author:       Andre Yim
   Subject:      ECOR 1606
   Assignment#5, Question #1
   Purpose:     The program will ask the user to enter a value, which the value will be the amount the user is willing to
   				spend on drink and food. The program will look for the best meal with the best amount of vitamin C. When -1
   				is input, the program will stop and output the most expensive meal, most economical and also the meal with the
   				least calories.
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
	while (amount > 35 || amount <= 0) {
		if (amount < 0) {
			cout << "The amount entered is invalid" << endl;
			cout << "Please enter the total amount of money you wish to spend on Food and Drink: ";
			cin >> amount;
		} else if (amount > 35) {
			cout << "The amount entered is too large, please spend less." << endl;
			cout << "Please enter the total amount of money you wish to spend on Food and Drink: ";
			cin >> amount;
		} else if (amount == 0) {
			break;
		}
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
	double costFood;
	double aFood = amount;
	
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
double selectDrink( double amount, int & vcDrink, int & calDrink ) { 
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
    double costDrink, costFood,
	   mostExpensiveMeal,
           Price;
           
	int calFood,
		calDrink,
		leastCalories,
		greatestVC,
		totalVC = 0,
		cal650Count = 0,
		mealCount = 0;
	double amount, aDrink = 0, aFood = 0;
	double vcDrink, vcFood;
	double bestComboFood = 0, bestComboDrink = 0, bestVC = 0;
	double price = 0, total = 0;
	double aTotal;
	int iFor, iMax;
	int count = 1, temp = 0 , calories = 0;
	do {
		amount = getMaxDollars();
		cout << "Some options are: " << endl;
		cout << setw(1) << "Option" << setw(10) << "Cost" << setw(15) << "Calories";
		cout << setw(15) << " Vit.C"<< setw(15) << "Description" << endl;
		while (price < amount){
			aTotal = price;
			iMax=int(aTotal/0.05 + 0.001);
	    	// Now loop through all the possible values to determine the best meal
	    	for ( iFor = 0 ; iFor <= iMax ; iFor++ ) {
	    	    aFood=iFor*0.05;
	    	    aDrink = aTotal - aFood;
		        if (aDrink >= 8.99){ 	vcDrink  = 236;		calDrink = 101;		aDrink = 8.99;	}
		        else if (aDrink >= 4.99) { 	vcDrink  = 207;		calDrink = 112;		aDrink = 4.99;	}
		        else if (aDrink >= 3.50) { 	vcDrink  = 50;		calDrink = 203;		aDrink = 3.50; 	}
		        else if (aDrink >= 2.50) { 	vcDrink  = 149;		calDrink = 250;		aDrink = 2.50;	}
		        else if (aDrink >= 1.75) { 	vcDrink  = 7;		calDrink = 2;		aDrink = 1.75;	}
		        else if (aDrink >= 1.25) { 	vcDrink  = 0;		calDrink = 0;		aDrink = 1.25;	}
		        else if (aDrink >= 0.95) { 	vcDrink  = 0;		calDrink = 0;		aDrink = 0.95;	}
		        else if (aDrink >= 0.25) { 	vcDrink  = 0;		calDrink = 160;		aDrink = 0.25;	}
		        else { 	vcDrink  = 0;		calDrink = 0;		aDrink = 0;	}			
	
		        if (aFood >= 24) {	vcFood  = 148;	calFood = 300;		aFood = 24;	}
				else if (aFood >= 14.99) {	vcFood  = 30;	calFood = 80;		aFood = 14.99;	}
		        else if (aFood >= 6.75) {	vcFood  = 9;	calFood = 200;		aFood = 6.75;	}
		        else if (aFood >= 3.50) {	vcFood  = 6;	calFood = 250;		aFood = 3.50;	}
		        else if (aFood >= 2.50) {	vcFood  = 12;	calFood = 301;		aFood = 2.50;	}
		        else if (aFood >= 1.00) {	vcFood  = 2;	calFood = 452;		aFood = 1.00;	}
		        else if (aFood >= 0.35) {	vcFood  = 0;	calFood = 436;		aFood = 0.35;	}
		        else {	vcFood  = 0;		calFood = 0;		aFood = 0;	}
	    	    
	    	    if ( aFood == 0 || bestVC < (vcFood + vcDrink) ) {
	    	        bestVC = vcFood + vcDrink;
	    	        bestComboFood = aFood;
	    	        bestComboDrink = aDrink;
	    	        calories = calDrink + calFood;
	    	    }
	    	}
		if ((bestComboFood+bestComboDrink > total) && (bestComboDrink > 5)){	
			cout << setw(1) << count << setw(15) << bestComboFood+bestComboDrink;
			cout << setw(15) << calories << setw(15);
			cout << bestVC << setw(18);
			printFood(bestComboFood);
			cout << " and ";
			printDrink(bestComboDrink);
			cout << endl;
			total = bestComboFood+bestComboDrink;
			count++;
		}
		price += 0.05;
	}
   	    
	} while (amount != 0);
	
	if (costFood+costDrink > 0) {
	
		    cout << "This meal would cost $" << costFood+costDrink
					<< ", with " << calFood+calDrink 
					<< " Calories and " << vcFood+vcDrink 
					<< "% of the daily required Vitamin C" << endl;
		    cout << endl;
		    
			mealCount++;
	
			if ( mealCount == 1 || mostExpensiveMeal < (costFood+costDrink) ) {
				mostExpensiveMeal = bestComboFood+bestComboDrink;
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
			
			if (mealCount > 0) {
			cout <<	"The most expensive meal costs: $" << mostExpensiveMeal << endl;
			cout << "The meal with the least calories had: " << leastCalories << " calories" << endl;
			cout << "The average vitamin C per meal was: " << totalVC/mealCount	<< endl;
			cout << "The most econmical source of 'C' was: " << greatestVC << "%/dollar" << endl;
			cout << 100*cal650Count/mealCount << "% of the meals had more than 650 calories." << endl;
		}
		
	} // End of sentinal loop.

	
	
    	   		    
    system("PAUSE"); return 0;
}

