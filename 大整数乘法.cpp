#include <iostream>

using namespace std; 

void multiplication(char* n, char* q, char* p)
{
	int lofq = -1, lofp = -1, i = 0, carry = -1, product = -1;
	
	for(i = 0; q[i] != 0 ; i++)
	{
		q[i] = q[i] - 48;
	}
	lofq = i;
	
	for(i = 0; p[i] != 0 ; i++)
	{
		p[i] = p[i] - 48;
	}
	lofp = i;
	
	for(int j = lofp -1, d=0; j >= 0; j--)
	{
		for(i = lofq - 1, carry = 0; i >= 0; i--)
		{
			product = q[i]*p[j];
			d = (product + carry + n[i + j + 1]);
			n[i + j + 1] = (char)(d % 10);
			carry = d / 10;
		}
		n[i + j + 1] = (char)carry;
	} 
	
	for(i = 0; i < lofq ; i++)
	{
		q[i] = q[i] + 48;
	}
	
	for(i = 0; i < lofp ; i++)
	{
		p[i] = p[i] + 48;
	}
	for(i = 0; i < lofp + lofq ; i++)
	{
		n[i] = n[i] + 48;
	}
}

int main()
{
	char q[1024] = {0}, p[1024] = {0}, n[1024] = {0};
	cin >> q >> p;

	multiplication( n, q, p);
	cout << n << endl;
	return 0;
} 
