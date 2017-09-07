#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int temp,index;
	int *hashTable = new int[m]();	
//	for(int i=0; i<m; i++)
//		hashTable[i] = -1
	cin >> temp;
	index = temp%m;
	hashTable[index] = temp;
	cout << index; 
	for(int i=0; i<n-1; i++)
	{
		cin >> temp;
		index = temp%m;
		while(hashTable[index] != 0&&hashTable[index] != temp)
		{
			index++;
			if(index >=m)
			index = 0;
		}
		hashTable[index] = temp;
		cout << " " << index;
	}
		
	return 0;
} 
