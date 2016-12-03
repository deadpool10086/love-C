#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
/*	cout << setfill('*') << setw(5) << 'a' << endl;
	for(int i=2; i<10; i++)
	{
		cout << setfill('*') << setw(i) << "abc"<< endl;
	} 
*/
	cout << "Enter a source file name: ";
	char inputFilename[40];
	cin >> inputFilename;
	
	cout << "Enter a target file name: ";
	char outputFilename[40];
	cin >> outputFilename;		
	
	ifstream input;
	ofstream output;
	
	input.open(inputFilename);
	if (input.fail())
	{
		cout << "error" << endl;
		return 0;
	}
	output.open(outputFilename);
	
	
	while (!input.eof() )
	{
		output.put(input.get());
	}
	
	return 0;
}
