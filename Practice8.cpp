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

int alpha ( int x, int &y) {
	cout << "PEAR" << x+y << endl;
	x=17; y=3;
	return x/y;
}

void beta (int x[], int n) {
	x[n] = x[0];
}

int main (void) {
	int a =17, b=7, c = 10, d = 0, i , j;
	int data[5] = {0,5,4,3,8};
	int t= 2;
	bool flag= true;
	
	for (i=1;i<5; i+=2) {
		t*=data[i];
	}
	
	b = alpha (a,c);
	cout << "APPLE " << a%5 << "	" << b <<  "	" << c << "		" << t << endl;
	
	i=1;
	do{
		d+=data[i];
		if (d>15 || i==3) {
			flag = false;
		}
		i = i + 1;
	} while (flag);
	
	beta (data, 3);
	
	cout << "ORANGE" << d << "	" << "	" << i << " 	" << data[3] << endl;
	
	for (i=12; i > 10; i--) {
		for (j=1;j<3;j++) {
			cout << "MELON" << i << "	" << j << endl;
		}
	}
	    
    system("PAUSE"); 
    return 0;
}
