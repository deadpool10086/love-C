#include  <iostream>
#include  <iomanip>
#include <fstream> 
using namespace std;

int main()
{
	fstream file;
	file.open("a.txt",ios::out|ios::in);
	file.put('a');
	file.close();
	file.open("a.txt",ios::out|ios::in);
	cout << static_cast<char>(file.get()) <<endl;
	file.close();
	return 0;
}
