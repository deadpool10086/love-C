#include <iostream>
#include <string>
#include "GenericStack.h"

/* 
��Ŀ����->����->c++������
 	-frepo  -fdump-tree-original

*/ 

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv) {
	Stack<int> intStack;
	for (int i=0; i<10; i++)
	{
		intStack.push(i); 
	 } 
	 
	while(!intStack.empty())
		cout << intStack.pop() << " ";
	cout << endl;	
	
	Stack<string> stringStack;
	
	stringStack.push("Beijing");
	stringStack.push("Shanghai");
	stringStack.push("Guangzhou");
	
	while(!stringStack.empty())
		cout << stringStack.pop() << " ";
	cout << endl;
	
	return 0;
}
