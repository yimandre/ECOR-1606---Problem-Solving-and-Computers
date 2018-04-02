// Assignment 3, Part 2
/* This program will allow the user to evaluate the most expensive meal, the meal with
   the least calories, the average amount of Vitamin C per meal, the most economic Vitamin C
   selection and percentage of meals that have more than 650 calories */ 
// Name: Andre Yim
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
	
	//Constant for drink

    // Variables
    double a = 0; // Will hold the amount of money available
    double aFood; // The amount of money you want to spend on Food
    double aDrink; // The amount of money you want to spend on Drinks
    double ExpensivePrice;
    double Price; //Most Expensive Meal
    double cost; //Price including drink and food
    double Calories; //Total Calories
    double LCals; //Least Calories
    double cal; //Calories for drinks
    double acal; // Calories for food
    double VitC; //Vitamin C Total
    double aVitC; //Vitamin C in Drink
    double bVitC; //Vitamin C in Food
    double meal; //numbers of loops
    double Vitavg; //average Vitmain C per meal
	double HiVit; //Highest Vitamin
	double BestVit;
	double TotCal;
	double PCal;
	double b; //Price of drink
	double c; //Price of food

    cout << "Please enter how much money you have available: ";
    cin >> a;
    Price = 0;
    VitC = 0;
    meal = 0;
    HiVit = 0;
    TotCal = 0;
    LCals = 700;
    
	while (a >= 0) {
		cout << "How much money would you like to spend on food? ($0 to terminate) ";
    	cin >> aFood;
    	cout << "How much money would you like to spend on drink? ($0 to terminate) ";
    	cin >> aDrink;
 
//If 0,0 is enter, stop program and display stats   	
    	if (aDrink == 0 && aFood == 0) {
    		cout << "The most expensive meal cost $" << Price << endl;
    		cout << "The meal with the least calories had " << LCals << endl;
    		cout << "The most ecomical source of Vitamin C is " << BestVit << "%/dollar" << endl;
    		cout << PCal << "of the meals had more than 650 calories" << endl;
			return 0;
		}
    			

// Collect the information		
		if (aDrink != 0 && aFood != 0) {
			meal = meal + 1;  
    		
			if (a>0 && aDrink>0) {
				if (a >= 8.99 && aDrink >= 8.99) {
					cout << "We recommend you purchase an OJ with Carrots & Spinach, for $8.99" << endl;
					aDrink = 8.99;
					cal = 101;
					aVitC = 239;
					b = 8.99;
				} else if (a >= 4.99 && aDrink >= 4.99) {
					aDrink = 4.99;
					cout << "We recommend you purchase an OJ, for $4.99" << endl;
					cal = 112;
					aVitC = 207;
					b = 4.99;
     			} else if (a >= 3.50 && aDrink >= 3.50) {
     				cout << "We recommend you purchase an Asparagus Milkshake, for $3.50" << endl;
            		aDrink = 3.50;
            		cal = 203;
            		aVitC = 50;
            		b = 3.50;
        		} else if (a >= 2.50 && aDrink >= 2.50) {
        			cout << "We recommend you purchase a Strawberry Milkshake, for $2.50" << endl;
           			aDrink = 2.50;
           			cal = 250;
           			aVitC = 149;
           			b = 2.50;
       			} else if (a >= 1.75 && aDrink >= 1.75) {
       				cout << "We recommend you purchase a Tea, for $1.75" << endl;
        			aDrink = 1.75;
        			cal = 2;
        			aVitC = 7;
        			b = 1.75;
        		} else if (a >= 1.25 && aDrink >= 1.25) {
        			cout << "We recommend you purchase a Water, for $1.25" << endl;
        			aDrink = 1.25;
        			cal = 0;
        			aVitC = 0;
        			b = 1.75;
        		} else if (a >= 0.95 && aDrink >= 0.95) {
        			cout << "We recommend you purchase a Coffee, for $0.95" << endl;
           			aDrink = 0.95;
           			cal = 0;
           			aVitC = 0;
           			b = 0.95;
        		} else if (a >= 0.25 && aDrink >= 0.25 ) {
        			cout << "You could purchase a Pop, for $0.25" << endl;
           			aDrink = 0.25;
           			cal = 0;
           			aVitC = 0;
           			b = 0.25;
        		} else {
           			cout << endl;
        		} // end if
			
//Food
			} if (a > 0 && aFood > 0) {
				if (a >= 24.00 && aFood >= 24.00) {
					cout << "You could purchase a Steak and Broccoli, for $24.99" << endl;
					aFood = 24.00;
           			acal = 300;
           			bVitC = 148;
           			c = 24.00;
				} else if (a >= 14.99 && aDrink >= 14.99) {
					cout << "You could purchase a Veggie Platter, for $14.99" << endl;
					aFood = 14.99;
           			acal = 80;
           			bVitC = 30;
           			c = 14.99;
     	   		} else if (a >= 6.75 && aFood >= 6.75) {
     	   			cout << "You could purchase a Submarine Sub, for $6.75" << endl;
            		aFood = 6.75;
           			acal = 200;
           			bVitC = 9;
           			b = 6.75;
        		} else if (a >= 3.50 && aDrink >= 3.50) {
        			cout << "You could purchase a Pepperoni, for $3.50" << endl;
            		aFood = 3.50;
           			acal = 250;
           			bVitC = 6;
           			c = 6.75;
        		} else if (a >= 2.50 && aDrink >= 2.50) {
        			cout << "You could purchase an All Dressed Hamburger, for $2.50" << endl;
            		aFood = 2.50;
           			acal = 301;
           			bVitC = 12;
           			b = 2.50;
        		} else if (a >= 1.00 && aDrink >= 1.00) {
        			cout << "You could purchase a doughnut, for $1.00" << endl;
           			aFood = 1.00;
           			acal = 452;
           			bVitC = 2;
           			c = 1.00;
        		} else if (a >= 0.35 && aDrink >= 0.35) {
        			cout << "You could purchase a Noodle Soup, for $0.35" << endl;
           			aFood = 0.35;
           			acal = 436;
           			bVitC = 0;
           			c = 0.35;
				} else {
        			cout << "The amount of money is not enough for you to buy food" << endl;
    			} // end if
    			
    			cout << "This meal will cost $" << aFood + aDrink << ", with " << acal + cal << " calories";
    			cout << " and " << aVitC + bVitC << "% of the daily required";
		   	
    		}
    	
//Calculate the most expensive meal
    		cost = aFood + aDrink;
			if (Price <= cost ) {
				Price = cost;
			} //endif
	
//Calculate the least Calories	
			Calories = cal + acal;
			if (Calories <= LCals) {
				LCals = Calories;
			} //end if
		
//Calculate the average amount of Vitamin C per meal
			VitC = 	aVitC + bVitC;
			Vitavg = VitC / meal;
		
//Calculate most economica Vitamin C meal selection
			if (HiVit <= VitC ) {
				HiVit = VitC;
				BestVit = (HiVit / cost)* 100;
			}
//Percentage of meals that have more than 650

			if (Calories >= 650) {
				TotCal = TotCal + Calories;
				PCal = (TotCal / meal)*100 ;
			}//end if
		
		}//endif
	}
	
		
    cout << endl;

    system("PAUSE"); return 0;

}
