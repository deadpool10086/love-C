#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATASUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int shell_sort(int *data,int sum);

int main(int argc, char *argv[]) {
	int data[DATASUM],i,sum;
	srand((unsigned)time(NULL));
	for(i=0,sum=0;i<10000;i++)
	{
		data[i]=rand();
		sum++;
	}
	shell_sort(data,sum);
	for(i=0;i<sum;i++)
	{
		printf("%d\t",data[i]);
		if(i!=0&&i%50==0)
		getchar();
	}
	return 0;
}

int  shell_sort(int *data,int sum)
{
	int max,i,j,k,temp;
	for(max=1;max<sum;max=max*2);
	for(max=max/4;max>1;max=max/2)
	{
		k=max-1;
		for(i=k;i<sum;i++)
		{
			temp=data[i];
			for(j=i;j>=k&&temp<data[j-k];j-=k)
			data[j]=data[j-k];
			data[j]=temp;
		}
	}
	return 0;
}
