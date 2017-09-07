#include <iostream>
#include <fstream>
using namespace std; 
int main()
{
	ifstream input;
	
	input.open("scores.txt");
	
	if (input.fail())
	{
		cout << "у╗ак"<< endl;
		exit(0);
	 } 
	
	char firstName[80];
	char mi;
	char lastName[80];
	int score; 
	
	input >> firstName >> mi >> lastName >> score;
	
	input.close();
	cout << "done" << endl;
	return 0;
 } 
