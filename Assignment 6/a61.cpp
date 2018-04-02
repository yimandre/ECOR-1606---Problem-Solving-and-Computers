/* This program is the will gather the amount of money that the user has and will calculate
the best meal that he/she could buy. Once the input is entered, this program will help the 
user to view the meals that are closest to cost, least calories and also the highest Vitamin C
contained in one meal. This program will loop until the value "0" is ented.

Name: Andre Yim
Student #: 100961929
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
//  getMaxDollars()
//      (1) Requests the user the amount of money they want to spend
//      (2) If the values are not valid, has the user 
//          try again, until a value in the range desired is 
//          entered
//  Returns:  the maximum dollars to spend.
// 
double getMaxDollars( void ) {
    double amount;
    // Input amount to spend
    for (;;) {
        cout << "Please enter the total amount of money you wish to spend on Food & Drinks:";
        cin >> amount ;
    	if ( amount < 0) { cout << "Error: amount must be positive" << endl; }
    	else if ( amount > 35 ) { cout << "Error: maximum amount you may spend is $35" << endl; }
    	else { return amount; }
    }   
}

//  fequals() - tests if two floating point values are (approximately) equal//
//  Returns: true if  ||b-a|| < 0.0001
//           false otherwise
bool fequals( double a , double b ) {  return fabs( b-a ) < 0.0001; }

// selectFood() 
//    Selects a food choice, given a maximum amount of money, but does not print anything.
// Returns:  cost of most expensive food that could be bought for the given 'amount'
//           also populates/"returns" the vitamin-C, and calories for the selected food
double selectFood( double amount, int &vcFood, int &calFood ) 
{
    double costFood = 0;
    if (amount >= 24) {	vcFood  = 148;	calFood = 300;		costFood = 24;	}
    else if (amount >= 14.99) {	vcFood  = 30;	calFood = 80;		costFood = 14.99;	}
    else if (amount >= 6.75) {	vcFood  = 9;	calFood = 200;		costFood = 6.75;	}
    else if (amount >= 3.50) {	vcFood  = 6;	calFood = 250;		costFood = 3.50;	}
    else if (amount >= 2.50) {	vcFood  = 12;	calFood = 301;		costFood = 2.50;	}
    else if (amount >= 1.00) {	vcFood  = 2;	calFood = 452;		costFood = 1.00;	}
    else if (amount >= 0.35) {	vcFood  = 0;	calFood = 436;		costFood = 0.35;	}
    else {			vcFood  = 0;	calFood = 0;		costFood = 0;	}

    return costFood;
}
// Prints the name of the food choice selected, for a given dollar value.
// This function uses the fequals() function defined above
//    The function should only print the food (e.g. "a Hamburger")
//    so that the same function can be used in a table as in an output string.
// selectDrink() 
//    Selects a drink choice, given a maximum amount of money, but does not print anything.
// Returns:  cost of most expensive drink that could be bought for the given 'amount'
//           also populates/"returns" the vitamin-C, and calories for the selected drink
double selectDrink( double amount, int &vcDrink, int &calDrink ) {
    double costDrink = 0;

    if (amount >= 8.99){ 	vcDrink  = 236;		calDrink = 101;		costDrink = 8.99;	}
    else if (amount >= 4.99) { 	vcDrink  = 207;		calDrink = 112;		costDrink = 4.99;	}
    else if (amount >= 3.50) { 	vcDrink  = 50;		calDrink = 203;		costDrink = 3.50; 	}
    else if (amount >= 2.50) { 	vcDrink  = 149;		calDrink = 250;		costDrink = 2.50;	}
    else if (amount >= 1.75) { 	vcDrink  = 7;		calDrink = 2;		costDrink = 1.75;	}
    else if (amount >= 1.25) { 	vcDrink  = 0;		calDrink = 0;		costDrink = 1.25;	}
    else if (amount >= 0.95) { 	vcDrink  = 0;		calDrink = 0;		costDrink = 0.95;	}
    else if (amount >= 0.25) { 	vcDrink  = 0;		calDrink = 160;		costDrink = 0.25;	}
    else { 			vcDrink  = 0;		calDrink = 0;		costDrink = 0;	}	
    // end if selecting the most expensive meal
    return costDrink;
}
 
 
// Prints the name of the drink choice selected, for a given dollar value.
// This function should use the fequals() function defined above
//    The function should only print the food (e.g. "a Strawberry Milkshake")
//    so that the same function can be used in a table as in an output string.
bool isKnownSolution(double meal, double drink, double mealCosts[], double drinkCosts[], int n){
	for (int i = 0; i < n; i++){
		 if (fequals(mealCosts[i],meal)) 
			return true; 
}
	return false;
}

void swapElements(int i, int j, double key[], double data1[], double data2[], double data3[]){
	double keyvalue = key[i];
	key[i] = key[j];
	key[j] = keyvalue;
	double value1 = data1[i];
	data1[i] = data1[j];
	data1[j] = value1;
	double value2 = data2[i];
	data2[i] = data2[j];
	data2[j] = value2;
	double value3 = data3[i];
	data3[i] = data3[j];
	data3[j] = value3;
}

void sortElements(int size, double key[], double data1[], double data2[], double data3[]){
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if (key[j] > key[i]){ swapElements(i, j, key, data1, data2, data3);}
		}
	}
}
void printFood( double amount ) {
    if ( fequals( amount, 24.00 ) ) { cout << "Steak & Broccoli";
    } else if ( fequals( amount, 14.99)) { cout << "a Veggie Platter";
    } else if ( fequals( amount, 6.75)) { cout << "a Submarine Sandwich";
    } else if ( fequals( amount, 3.50)) { cout << "a Pepperoni Pizza";
    } else if ( fequals( amount, 2.50)) { cout << "an all dressed Hamburger";
    } else if ( fequals( amount, 1.00)) { cout << "a Doughnut";
    } else if ( fequals( amount, 0.35)) { cout << "a Noodle soup";
    } else { cout << "no food";
    } // end if
  
}
void printDrink( double amount ) {
    if ( fequals( amount, 8.99)) { cout << "OJ with Carrots & Spinach";
    } else if ( fequals( amount, 4.99)) { cout << "an OJ";
    } else if ( fequals( amount, 3.50)) { cout << "an Asparagus Milkshake";
    } else if ( fequals( amount, 2.50)) { cout << "a Strawberry Milkshake";
    } else if ( fequals( amount, 1.75)) { cout << "a Tea";
    } else if ( fequals( amount, 1.25)) { cout << "a Water";
    } else if ( fequals( amount, 0.95)) { cout << "a Coffee";
    } else if ( fequals( amount, 0.25)) { cout << "a Pop";
    } else { cout << "no drink";
    } // end if selecting the most expensive meal
}
int main (void) {
    // Variables
    double aTotal, aDrink, aFood,      // Will hold the amount of money available
           costDrink, costFood, mostExpensiveMeal,
	   greatestVC, bestVC,                     // The meal combination with the most vitamin C
           bestCal,  bestComboFood, bestComboDrink;
           
           
	int calFood, calDrink, vcFood, vcDrink,
		leastCalories, option,
		totalVC = 0, cal650Count = 0,
		mealCount = 0, iFor, iMax;
    // Arrays
    double drinkCosts[] = {3.50,0.95,4.99,8.99,0.25,2.50,1.75,1.25,0};
    int vcMeals[] = {50, 52, 62, 56, 59, 80, 198, 50, 0, 2, 12, 6, 9, 30, 148, 
			0, 207, 209, 219, 213, 216, 237, 355, 207, 236, 238, 248, 
			242, 245, 266, 384, 236, 0, 2, 12, 6, 9, 30, 148, 0, 149, 
			151, 161, 155, 158, 179, 297, 149, 7, 9, 19, 13, 16, 37, 
			155, 7, 0, 2, 12, 6, 9, 30, 148, 0, 0, 2, 12, 6, 9, 30, 148, 0};
    double totalCosts[] = {3.85, 4.5, 6.0, 7.0, 10.25, 18.49, 27.5, 3.5, 1.30, 1.95, 
			3.45, 4.45, 7.7, 15.94, 24.95, 0.95, 5.34, 5.99, 7.49, 8.49, 
			11.74, 19.98, 28.99, 4.99, 9.34, 9.99, 11.49, 12.49, 15.74, 
			23.98, 32.99, 8.99, 0.6, 1.25, 2.75, 3.75, 7.0, 15.24, 24.25, 
			0.25, 2.85, 3.5, 5.0, 6.0, 9.25, 17.49, 26.5, 2.5, 2.1, 2.75, 
			4.25, 5.25, 8.5, 16.74, 25.75, 1.75, 1.6, 2.25, 3.75, 4.75, 
			8.0, 16.24, 25.25, 1.25, 0.35, 1.0, 2.5, 3.5, 6.75, 14.99, 24.0, 0.0};
    int calMeals[] = {639, 655, 504, 453, 403, 283, 503, 203, 436, 452, 301, 250, 200, 
			80, 300, 0, 548, 564, 413, 362, 312, 192, 412, 112, 537, 553, 
			402, 351, 301, 181, 401, 101, 596, 612, 461, 410, 360, 240, 
			460, 160, 686, 702, 551, 500, 450, 330, 550, 250, 438, 454, 
			303, 252, 202, 82, 302, 2, 436, 452, 301, 250, 200, 80, 300, 
			0, 436, 452, 301, 250, 200, 80, 300, 0};
    double mealCosts[72];
    double costs[72];
    double vc[72];
    double cal[72];
    // Set the formatting to 2 decimal places    
    cout << setiosflags (ios::showpoint | ios::fixed) << setprecision(2);
         
    // Sentinel loop.  Exit if amount to spend is zero.
    for (;;) {
	int max = 0;
	
	aTotal = getMaxDollars();
	if ( aTotal == 0 ) { break; }
	option = 0;
	
	iMax=int(aTotal/0.05 + 0.001);
    	
	// Now loop through all the possible values to determine the best meal
    	for ( iFor = 0 ; iFor <= iMax ; iFor++ ) {
    	    aFood=iFor*0.05;
    	    aDrink = aTotal - aFood;
    	    costFood = selectFood( aFood , vcFood , calFood );
    	    costDrink= selectDrink( aDrink, vcDrink, calDrink );

    	    if ( iFor == 0 || bestVC < (vcFood + vcDrink) ) {
    	        bestVC = vcFood + vcDrink;
    	        bestCal = calFood + calDrink;
    	        bestComboFood = costFood;
    	        bestComboDrink = costDrink;
    	    }

	    // isKNownSolution;
	    bool solution = false;
	    for (int i = 0; i < 72; i++)
	    {if (fequals(totalCosts[i], costDrink+costFood)) solution = true; }

	    if(solution){
		if (!(isKnownSolution(costFood + costDrink, costDrink, mealCosts, drinkCosts, max))){
			int i = 0;
			mealCosts[max] = costFood + costDrink;
	    		costs[max] = costFood + costDrink;
			for (i = 0; i < 72; i++)
			{if (fequals(totalCosts[i],costs[max])){ break; } }
    			vc[max] = vcMeals[i];
    			cal[max] = calMeals[i];
			max++;
		}
	     }

    	}

	sortElements(max,  mealCosts, costs, vc, cal);
//	cout << endl << "Some options closest cost are: " << endl;
//	cout << "Option" << setw(5) << "Cost" << setw(10) << "Calories" << setw(10) << "Vit.C" << setw(15) << "Description" << endl;
//	
//	for (int i = 0; i < max; i++){
//		cout << i+1 << setw(10) << setprecision(2) << costs[i] << setw(10) << setprecision(0) << cal[i];
//		cout << setw(10) << setprecision(0) << vc[i]<< setw(10);
//		
//		int j = 0;
//		while (j < 72){	if (fequals(totalCosts[j], costs[i])) {break;}	j++; }
//
//		printFood(costs[i] - drinkCosts[j/8] );
//		//cout <<  setprecision(2) << costs[i]-drinkCosts[j/8];
//    		cout << " and ";
//       		printDrink( drinkCosts[j/8] );
//		//cout <<  setprecision(2) << drinkCosts[j/8];
//       	 	cout << endl;
//	}

//	cout << endl << endl <<"Break: " << max << endl << endl;
	int upto = max;
	sortElements(max,  mealCosts, costs, vc, cal);
	upto = max;
	if (max > 6){ upto = 6; }

	cout << endl << "Some options closest cost are: " << endl <<"Option" << setw(5) << "Cost";
	cout << setw(10) << "Calories" << setw(10) << "Vit.C" << setw(15) << "Description" << endl;
	
	for (int i = 0; i < upto; i++){
		cout << i+1 << setw(10) << setprecision(2) << costs[i] << setw(10) << setprecision(0);
		cout << cal[i] << setw(10) << setprecision(0) << vc[i]<< setw(10);

		int j = 0;
		while (j < 72){
			if (fequals(totalCosts[j], costs[i])) break;
			j++;
		}
		printFood(costs[i] - drinkCosts[j/8] );
    		cout << " and ";
       		printDrink( drinkCosts[j/8] );
       	 	cout << endl;
	}


	upto = max;
	sortElements(max,  cal, costs, vc, mealCosts);
	upto = max;
	if (max > 6){ upto = 6; }

	cout << endl << "Some options with the lowest calories are: " << endl <<"Option" << setw(5) << "Cost";
	cout << setw(10) << "Calories" << setw(10) << "Vit.C" << setw(15) << "Description" << endl;
	
	for (int i = 0; i < upto; i++){
		cout << i+1 << setw(10) << setprecision(2) << costs[i] << setw(10) << setprecision(0);
		cout <<  vc[i] << setw(10) << setprecision(0) << cal[i] << setw(10);

		int j = 0;
		while (j < 72){
			if (fequals(totalCosts[j], costs[i])) break;
			j++;
		}
		printFood(costs[i] - drinkCosts[j/8] );
    		cout << " and ";
       		printDrink( drinkCosts[j/8] );
       	 	cout << endl;
	}



	upto = max;
	sortElements(max,  vc, costs, cal, mealCosts);
	upto = max;
	if (max > 6){ upto = 6; }

	cout << endl << "Some options with the highest Vit.C are: " << endl <<"Option" << setw(5) << "Cost";
	cout << setw(10) << "Calories" << setw(10) << "Vit.C" << setw(15) << "Description" << endl;
	
	for (int i = 0; i < upto; i++){
		cout << i+1 << setw(10) << setprecision(2) << costs[i] << setw(10) << setprecision(0);
		cout << cal[i] << setw(10) << setprecision(0) << vc[i]<< setw(10);

		int j = 0;
		while (j < 72){
			if (fequals(totalCosts[j], costs[i])) break;
			j++;
		}
		printFood(costs[i] - drinkCosts[j/8] );
    		cout << " and ";
       		printDrink( drinkCosts[j/8] );
       	 	cout << endl;
	}



        // Gather statistics
	if (bestComboFood+bestComboDrink > 0) {
    	
        	// Now Print the best solution:
        	cout << endl;
        	cout << "We recommend you purchase " ; 
                printDrink( bestComboDrink );
                cout << " for $" << bestComboDrink << " along with ";
                printFood( bestComboFood );
                cout << " for $" << bestComboFood << endl << endl ;
		cout << "This meal would cost $" << bestComboFood+bestComboDrink << ", with " 
		<< bestCal << " Calories and " << endl << "                     " 
		<< bestVC<< "% of the daily required Vitamin C" << endl << endl;
	    
		mealCount++;

		if ( mealCount == 1 || mostExpensiveMeal < (bestComboFood+bestComboDrink) ) 
		{ mostExpensiveMeal = bestComboFood+bestComboDrink; }
		if ( mealCount == 1 || leastCalories > (bestCal)) { leastCalories = bestCal; }
		totalVC += bestVC;
		if ( mealCount == 1 || greatestVC < bestVC/(bestComboFood+bestComboDrink) )
		{ greatestVC = bestVC/(bestComboFood+bestComboDrink); }
		if ( bestCal > 650) { cal650Count++; }
		
	}
		
    } // End of sentinal loop.
    if (mealCount > 0) {
	cout <<	"The most expensive meal costs: $" << mostExpensiveMeal << endl;
	cout << "The meal with the least calories had: "  << leastCalories << " calories" << endl;
	cout << "The average vitamin C per meal was: " << double(totalVC)/mealCount  <<"% " << endl;
	cout << "The most economical source of 'C' was: " << greatestVC << "%/dollar" << endl;
	cout << 100*cal650Count/mealCount << "% of the meals had more than 650 calories." << endl;
    }
    system("PAUSE"); 
    return 0;
}
