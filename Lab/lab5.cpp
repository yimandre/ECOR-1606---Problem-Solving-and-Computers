// Lab 5:
// This program converts integers between 1 and 3999 into roman numerals
// Name: Andre Yim
// Student Number:100961929


#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;


int main (void) {
	
	
    // INSERT YOUR CONSTANT DECLARATIONS HERE
    
    // INSERT YOUR VARIABLE DECLARATIONS HERE
    
    int value;
    int thousands;
    int hundreds;
    int tens;
    int ones;
    int remainder;
            
    // INSERT YOUR STATEMENTS HERE
    
    
    //Step One
    //Process the value
    cout << "Enter a value: ";
    cin >> value;
    
    while (value < 0) {
   	//Process the value
    	cout << "Processing not yet implemented" << endl;
    	cout << "Enter a value: ";
    	cin >> value;
    } //end while
    
    // Step Two
    if (value < 1 || value > 3999){ 
		cout << "Invalid value ignored" << endl;
 	}else{
		cout << endl << value << " in Roman Numerals is ";
    	thousands = value/1000;
    	
		while (thousands != 0){
       		cout << "M";
      		thousands = thousands - 1;
     	}
     	
		remainder = value % 1000;
    	hundreds = remainder / 100;
    	
		if ((hundreds >= 9)) {
    		cout << "CM";
    	} else 
			if ((hundreds < 5 && hundreds >= 4)) {
    			cout << "CD";
    		} else {
    			if ((hundreds >= 5)){
    				cout << "D";
    				hundreds = hundreds - 5;
    			} //endif
    			while (hundreds > 0){
    				cout << "C";
    				hundreds = hundreds - 1;
    			} //endwhile
    		} //endif

    	remainder = value % 100;
    	tens = remainder / 10;
    	

		if ((tens >= 9)) {
    		cout << "XC";
    	} else 
			if ((tens < 5 && tens >= 4)) {
    			cout << "XL";
    		} else {
    			if ((tens >= 5)){
    				cout << "L";
    				tens = tens - 5;
    			} //endif
    			while (tens > 0){
    				cout << "X";
    				tens = tens - 1;
    			} //endwhile
    		} //endif
	
    	
    	ones = remainder % 10;

		if ((ones >= 9)) {
    		cout << "IX";
    	} else 
			if ((ones < 5 && ones >= 4)) {
    			cout << "IV";
    		} else {
    			if ((ones >= 5)){
    				cout << "V";
    				ones = ones - 5;
    			} //endif
    			while (ones > 0){
    				cout << "I";
    				ones = ones - 1;
    			} //endwhile
    		} //endif
		  	
     	remainder = 0;	    
		return 0;

	}//endif
} 
     
    
