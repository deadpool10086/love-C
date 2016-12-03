#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int merge(int *data, int *tempData, int left, int leftEnd, int rightEnd)
{
	int right = leftEnd+1;
	int temp = left;
	int begin = left;
	while(left <= leftEnd && right <= rightEnd)
	{
		if (data[left] <= data[right])
		{
			tempData[temp++] = data[left++];
		}
		else
		{
			tempData[temp++] = data[right++];
		}		
	}
	while(left <= leftEnd)
	{
		tempData[temp++] = data[left++];
	}
	for (; begin < right; begin++)
	{
		data[begin] = tempData[begin];
	}
	return 0;
}

int merge1(int *data, int *tempData, int left, int right, int rightEnd)
{
	int leftEnd = right-1;
	int temp = left;
	int begin = left;
	while(left <= leftEnd && right <= rightEnd)
	{
		if (data[left] <= data[right])
		{
			tempData[temp++] = data[left++];
		}
		else
		{
			tempData[temp++] = data[right++];
		}		
	}
	while(left <= leftEnd)
	{
		tempData[temp++] = data[left++];
	}
	while(right <= rightEnd)
	{
		tempData[temp++] = data[right++];
	}
	
	return 0;
}

int msort_0(int *&data, int *&tempData, int n)
{
	int * temp;
	for (int lenth=1; lenth<=n; lenth*=2)
	{
		int i;
		for (i=0; i <= n-lenth*2 ; i+=lenth*2)
		merge1(data, tempData, i, i+lenth, i+2*lenth-1);
		if (i + lenth < n)
		{
			merge1(data, tempData, i, i+lenth, n-1);
		}
		else
		{
			while (i <= n)
			{
				tempData[i] = data[i];
				i++;
			}
		}
		temp = data;
		data = tempData;
		tempData = temp;
	}
	
	
	return 0;
}

int msort_1(int *data, int *tempData, int left, int right)
{
	if(left < right)
	{
		int center = (right - left)/2 + left;
		msort_1(data, tempData, left, center);
		msort_1(data, tempData, center+1, right);
		merge(data, tempData, left, center, right); 
	}
	return 0;
}

int merge_sort(int sum, int * &data)
{
	int *tempData;
	tempData = new int[sum];
	//msort_1(data, tempData, 0, sum);
	msort_0(data, tempData, sum);
	delete tempData;
	return 0;
}

int verification(int sum, int * data)
{
	for(int i=1; i<sum; i++)
	{
		cout << data[i] << "  ";
		if(data[i-1]>data[i])
			return 1;
	}
	return 0;
}

int main(int argc, char** argv) {
	
	srand((unsigned)time(0));
	
	int numberOfInteger = 100000;
	int * dataNumbers = 0;
	dataNumbers = new int[numberOfInteger];
	for (int i=0; i<numberOfInteger; i++)
	{
		dataNumbers[i] = rand();
	}
	
	merge_sort(numberOfInteger, dataNumbers);
	
	if (verification(numberOfInteger, dataNumbers))
	{
		cout << "sort error" << endl;
	}
	else
	{
		cout << "ok!" << endl;
	} 
	
	delete dataNumbers;
	return 0;
}
