#include <iostream>
#include <cstdlib> 
using namespace std;

int main ()
{
	char table[16][5] = {"0000","0001","0010","0011","0100","0101","0110",
		"0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	unsigned int c;
	string temp;
	temp.clear();
	char data[1000] = {0};
	cin >> data;
	for (int i=0; data[i]!=0; i++)
	{
		if(data[i]>57)
		{
			c = data[i] - 55;
		}
		else
		{
			c = data[i]-48; 
		} 
		
		temp += table[c];
	}
	cout << temp << endl;
	getchar(); 
	return 0;
 } 
