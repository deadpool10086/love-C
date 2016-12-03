#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATASUM 100000
#define RADIX 10
#define MAXDIGIT 4 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node shuju;
typedef struct HeadNode tong;

struct Node
{
	int key;
	struct Node *next;
};

struct HeadNode
{
	struct Node *head,*last;
};

void radix_sort(int *data,int sum);

int getdigit(int data,int digit)
{
	int d,i;
	for(i = 0; i < digit; i++)
	{
		d = data%RADIX;
		data = data / RADIX;
	}
	return d;
}

int main(int argc, char *argv[]) {
	int data[DATASUM],i,sum;
	srand((unsigned)time(NULL));
	for(i=0,sum = 0;i < 10000;i++)
		data[sum++]=rand()%10000;
	radix_sort(data,sum);
	for(i=0;i<sum;i++)
	printf("%d\t",data[i]);
	return 0;
}

void radix_sort(int *data,int sum)
{
	int i,d,di;
	shuju *temp,*list=NULL,*p;
	tong bucket[RADIX];
	for(i=0;i<RADIX;i++)
	bucket[i].head = bucket[i].last = NULL;
	for(i=0;i<sum;i++)
	{
		temp = (shuju *)malloc(sizeof(shuju));
		temp->key=data[i];
		temp->next=list;
		list = temp;
	}
	for(d=1;d<=MAXDIGIT;d++)
	{
		temp = list;
		while(temp)
		{
			p = temp;
			temp = temp->next;
			p->next=NULL;
			di = getdigit(p->key, d);
			if(bucket[di].head == NULL)
			bucket[di].head = bucket[di].last = p;
			else
			{
				bucket[di].last->next = p;
				bucket[di].last = p;
			}
		}
		list = NULL;
		for(i = RADIX-1;i >= 0; i--)
		{
			if(bucket[i].head != NULL)
			{
				bucket[i].last->next = list;
				list = bucket[i].head;
				bucket[i].head = bucket[i].last = NULL;
			}
		}
	}
	for(i = 0;i < sum;i++)
	{
		temp = list;
		data[i] = list->key;
		list = list->next;
		free(temp);
	}
}
