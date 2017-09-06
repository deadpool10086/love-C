#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATASUM 100000
#define RADIX 10
#define MAXDIGIT 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{
	int key;
	struct Node *next;
};

struct HeadNode
{
	struct Node *head,*last;
};

void msd(int *data,int l,int r,int d);
void msdradix_sort(int *data,int sum);
int getdigit(int data,int d);

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int data[DATASUM],i,sum;
	for(i=0,sum=0;i<10000;i++)
	{
		data[i] = rand()%10000;
		sum++;
	}
	msdradix_sort(data,sum);
	for(i = 0; i < sum; i++)
	printf("%d\t",data[i]);
	return 0;
}

void msd(int *data,int l,int r,int d)
{
	struct HeadNode bucket[RADIX];
	if(d==0)
	return;
	int i,z,di;
	struct Node *temp,*list=NULL,*p;
	for(i=0;i<RADIX;i++)
	bucket[i].head=bucket[i].last=NULL;
	for(i=l;i<=r;i++)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->key=data[i];
		temp->next=list;
		list=temp;
	}
	p=list;
	while(p)
	{
		di=getdigit(p->key,d);
		temp=p;p=p->next;
		temp->next=NULL;
		if(bucket[di].head==NULL) 
		bucket[di].last=temp;
		temp->next=bucket[di].head;
		bucket[di].head = temp;
	}
	i=z=l;
	for(di=0;di<RADIX;di++)
	{
		if(bucket[di].head)
		{
			p = bucket[di].head;
			while(p)
			{
				temp=p;
				p=p->next;
				data[z]=temp->key;
				z++;
				free(temp);
			}
			msd(data,i,z-1,d-1);
			i=z;
		}
	}
}

int getdigit(int data,int d)
{
	int i,n;
	for(i=0;i<d;i++)
	{
		n=data%RADIX;
		data = data/RADIX;
	}
	return n;
}

void msdradix_sort(int *data,int sum)
{
	msd(data,0,sum-1,MAXDIGIT);
}

