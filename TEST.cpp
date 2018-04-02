// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name:
// Student Number:

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;




int main (void) {
	ofstream fout;
	
	fout.open("output.txt");
	if (fout.fail()){
		cout << "Unable to open the output file.\n";
		system("PAUSE");
		return 0;
	}
	
	fout << "This is the first file line" << endl;
	fout << "This is the second fil line\.n";
	
	fout.close();

}
    system("PAUSE"); return 0;

}
