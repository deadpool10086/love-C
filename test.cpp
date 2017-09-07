#include <iostream>
#include <string>
#include <sstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
int main(int argc, char** argv) {
	string str,c1,c2;
	getline(cin,str);
	istringstream str1(str);
	str1 >> c1 >> c2;
	cout << c1 <<endl;
	cout << c2 <<endl;
	cout <<str << endl; 
	c1.clear() ;
	str1 >> c1;
	cout << c1.empty() << c1  << endl; 
	return 0;
}
