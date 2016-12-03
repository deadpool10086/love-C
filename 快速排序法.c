#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATANUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void quick_sort(int *data,int sum);
void swap(int *a,int *b);
void quicksort(int *data,int left,int right);
int medina(int *l,int *m,int *r);
void insert_sort(int *data,int sum);


int valve=100;

int main(int argc, char *argv[]) {
	int data[DATANUM];
	int i,sum,t;
	int test[]={10,100,300,600,1000};
	srand((unsigned)time(NULL));
	clock_t star,stop;
	for(t=0;t<5;t++)
	{
		valve=test[t];
		for(i=0,sum=0;i<10000;i++)
			{
				data[i]=rand();
				sum++;
			}
		star=clock();
		quick_sort(data,sum);
		stop = clock();
		printf("阈值为%d速度：%f\n",test[t],((double)(stop - star))/CLK_TCK);
	}
	return 0;
}

void quick_sort(int *data,int sum)
{
	quicksort(data,0,sum-1);
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void quicksort(int *data,int left,int right)
{
	int pivot,i=0,j=0;
	if(right-left>valve)
	{
		pivot=medina(data+left,data+(left+right)/2,data+right);
		i=left; j=right-1;
		while(1)
		{
			while(data[++i]<pivot)
			{	}
			while(data[--j]>pivot)
			{	}
			if(i<j)
			{swap(data+i,data+j);}
			else break;
		}
		swap(data+i,data+right-1);
		quicksort(data,left,i-1);
		quicksort(data,i+1,right);
	}
	else
	insert_sort(data+left,right-left+1);
}

int medina(int *l,int *m,int *r)
{
	if(*l>*m)
	swap(l,m);
	if(*l>*r)
	swap(l,r);
	if(*m>*r)
	swap(m,r);
	swap(m,r-1);
	return *(r-1);
}

void insert_sort(int *data,int sum)
{
	int i,j,temp;
	for(i=1;i<sum;i++)
	{
		temp=data[i];
		for(j=i;temp<data[j-1]&&j>0;j--)
			data[j]=data[j-1];
		data[j]=temp;
	}
}
