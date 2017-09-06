#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATANUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bubble_sort(int *data,int sum);

int main(int argc, char *argv[]) {
	clock_t start,stop;
	srand((unsigned)time(NULL));
	int data[DATANUM],i=0,sum=0;
	for(i=0;i<10000;i++)
	{
		data[i]=rand();
		sum++;
	}
	start = clock();
	bubble_sort(data,sum);
	stop = clock();
	printf("%f",((double)(stop-start))/CLK_TCK);
	return 0;
}

void bubble_sort(int *data,int sum)
{
	int s=0,i=0,temp=0,flag;
	s=sum-1;
	for(s;s>0;s--)
	{
		flag=0;
		for(i=0;i<s;i++)
		{
			if(data[i]>data[i+1])
			{
				temp=data[i+1];
				data[i+1]=data[i];
				data[i]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
