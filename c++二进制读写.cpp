#include <iostream>
#include <fstream>

using namespace std; 

int main()
{
	int a=100;
	
	fstream binaryio;
	binaryio.open("temp.dat", ios::out | ios::binary);
	
	binaryio.write(reinterpret_cast<char *>(&a), sizeof(a));
	binaryio.close(); 
	
	a = 0;
	binaryio.open("temp.dat", ios::in | ios::binary);
	
	binaryio.read(reinterpret_cast<char *>(&a), sizeof(a));
	binaryio.close(); 
	
	cout << a << endl;
	return 0;
 } 
