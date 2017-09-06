#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATANUM 100000

void merge_sort(int *data,int sum);
void merge(int *data,int*temp,int l,int r,int rend);
void mergepass(int *data,int *temp,int length,int sum);

int main(int argc, char** argv) {
	int data[DATANUM];
	int i,sum=0;
	srand((unsigned)time(NULL));
	for(i=0;i<10000;i++)
	{
		data[i]=rand();
		sum++;
	}
	merge_sort(data,sum);
	for(i=0;i<10000;i++)
	{
		printf("%d\t",data[i]);
	}
	return 0;
}

void merge_sort(int *data,int sum)
{
	int *temp,length;
	temp=(int *)malloc(sizeof(int)*sum);
	if(temp!=NULL)
	{
		length=1; 
		while(length<sum)
		{
			mergepass(data,temp,length,sum);
			length*=2;
			mergepass(temp,data,length,sum);
			length*=2;
		}
		free(temp);
	}
	else
	{
		printf("error");
		exit(0);
	}
}
void merge(int *data,int*temp,int l,int r,int rend)
{
	int n,lend;
	n=l;
	lend=r-1;
	while(l<=lend&&r<=rend)
	{
		if(data[l]<=data[r])
		temp[n++]=data[l++];
		else
		temp[n++]=data[r++];
	}
	while(l<=lend)
	{
		temp[n++]=data[l++];
	}
	while(r<=rend)
	{
		temp[n++]=data[r++];
	}
}
void mergepass(int *data,int *temp,int length,int sum)
{
	int i;
	for(i=0;i<=sum-length*2;i=length*2+i)
	{
		merge(data,temp,i,i+length,i+2*length-1);
	}
	if(i+length<sum)
	{
		merge(data,temp,i,i+length,sum-1);
	}
	else
	while(i<=sum)
	{
		temp[i]=data[i];
		i++;
	}
}
