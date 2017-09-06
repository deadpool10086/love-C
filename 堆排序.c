#include <stdio.h>
#include <stdlib.h>
#define DATANUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void heap_sort(int *data,int sum);
void adjust(int *p,int n,int sum);

int main(int argc, char *argv[]) {
	int data[DATANUM],sum;
	int i;
	for(i=0,sum=0;i<10;i++)
	{
		data[i]=rand();
		sum++;
	}
	heap_sort(data,sum);
	for(i=0;i<sum;i++)
	{
		printf("%d\t",data[i]);
	}
	return 0;
}

void heap_sort(int *data,int sum)
{
	int n,i;
	for(n=(sum-1)/2;n>=0;n--)
	{
		adjust(data,n,sum);
	}
	for(i=sum-1;i>0;i--)
	{
		n=data[i];
		data[i]=data[0];
		data[0]=n;
		adjust(data,0,i);
	}
}

void adjust(int *p,int n,int sum)
{
	int temp,parent,child;
	temp=p[n];
	for(parent=n;parent*2+1<sum;parent=child)
	{
		child=parent*2+1;
		if(parent*2+2<sum&&p[parent*2+1]<p[parent*2+2])
			child=parent*2+2;
		if(temp<p[child])
		p[parent]=p[child];
		else
		break;
	}
	p[parent]=temp;
}
