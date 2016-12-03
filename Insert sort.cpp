#include <iostream>
#include <ctime>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int insert_sort(int sum, int *data)
{
	int temp;
	for(int i=1; i<sum; i++)
	{
		temp = data[i];
		int j;
		for(j=i-1; data[j]>temp&&j!=0; j--)
		{
			data[j+1] = data[j];
		}
//		if ((j+1) != i)   //经过六次实验，对于是否判断后再进行放置当前对速度无影响 
		temp = data[j+1]; 
	}
	
	return 0;
}

int verification(int sum, int *data)
{
	for(int i=1; i<sum; i++)
	{
		if(data[i-1]>data[i])
			return 1;
	}
	return 0;
}

int main(int argc, char** argv) {
	
	clock_t start,stop;
	
	srand((unsigned)time(0));
	int numberOfInteger = 200000;
	int *dataNumbers = 0;
	dataNumbers = static_cast<int *>(malloc(sizeof(int)*numberOfInteger));
	if (!dataNumbers)
	{
		cout << "memory error" << endl;
		return 0;
	}
	for(int i=0; i<numberOfInteger; i++)
	{
		dataNumbers[i] = rand();
	}
	
	start = clock();
	insert_sort(numberOfInteger, dataNumbers);
	stop = clock();
	
//	if (verification(numberOfInteger, dataNumbers))
//	{
//		cout << "sort error" << endl;
//	}
//	else
//	{
//		cout << "ok!" << endl;
//	}
	free(dataNumbers); 
	cout << "排序耗时" 
		<< static_cast<double>(stop - start)/CLK_TCK << endl;
	return 0;
}


