#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATANUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insert_sort(int *data,int sum);

int main(int argc, char *argv[]) {
	int data[DATANUM],i,sum;
	srand((unsigned)time(NULL));
	for(i=0,sum=0;i<10000;i++)
	{
		data[i]=rand();
		sum++;
	}
	insert_sort(data,sum);
	return 0;
}

void insert_sort(int *data,int sum)
{
	int i,temp,j;
	for(i=1;i<sum;i++)
	{
		temp=data[i];
		for(j=i;i>0&&temp<data[j-1];j--)
				data[j]=data[j-1];
		data[j]=temp;
	}
}
