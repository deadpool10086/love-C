#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	ofstream output;
	
	output.open("scores.txt");
	for(int i=0; i <102400; i++) 
	output << "John" << ' ' << 'T' << " "  << " Smith"
		<< " " << 90  << endl; 
	
	output.close();
	return 0;
}
