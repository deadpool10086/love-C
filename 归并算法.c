#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATANUM 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void merge(int *data,int *temp,int l,int r,int rend);
void merge_sort(int *data,int sum);
void msort(int *data,int *temp,int l,int rend);

int main(int argc, char *argv[]) {
	int data[DATANUM];
	int i,sum;
	srand((unsigned)time(NULL));
	for(i=0,sum=0;i<10000;i++)
	{
		data[i]=rand();
		sum++;
	}
	merge_sort(data,sum);
	for(i=0;i<10000;i++)
	printf("%d\t",data[i]);
	return 0;
}

void merge(int *data,int *temp,int l,int r,int rend)
{
	int i,lend,n,sum;
	lend=r-1;
	n=l;
	sum=rend-l+1;
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
	for(i=0;i<sum;i++)
	{
		data[rend]=temp[rend];
		rend--;
	}
}

void merge_sort(int *data,int sum)
{
	int *temp;
	temp=(int *)malloc(sum*sizeof(int));
	if(temp!=NULL)
	{
		msort(data,temp,0,sum-1);
		free(temp);
	}
	else
	{
		printf("error");
		exit(0);
	}
}

void msort(int *data,int *temp,int l,int rend)
{
	if(l<rend)
	{
		msort(data,temp,l,(l+rend)/2);
		msort(data,temp,(l+rend)/2+1,rend);
		merge(data,temp,l,(l+rend)/2+1,rend);
	}
}
