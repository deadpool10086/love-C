#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TESTNUM 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node
{
	int data;
	int height;
};

void insert(struct node *tree,int d,int location);
void singleleftrotation(struct node *tree,int location);
void singlerightrotation(struct node *tree,int location);
void doubleleftrightrotation(struct node *tree,int location);
void doublerightleftrotation(struct node *tree,int location);
int xiangjian(struct node *a,struct node *b);
int max(struct node *a,struct node *b);

int main(int argc, char *argv[]) {
	struct node tree[TESTNUM]={0}; 
	int i,d,j;
	int compare[100]={0};
	srand((unsigned)time(NULL));
	for(i=0;i<31;i++)
	{
		d=rand();
		compare[i]=d;
 		insert(tree,d,0);
		d=0;
		for(j=0;d<100;d++)
		{
			printf("%d\t",(tree+d)->data);
			if(j==d)
			{
				printf("\n");
				j=j*2+2;
			}
		}
		printf("\n");
	}
	printf("%d\n",tree->height);
	return 0;
}

void insert(struct node *tree,int d,int location)
{
	if((tree+location)->data==0)
	{
		(tree+location)->data=d;
	}
	else if(d<(tree+location)->data)
	{
		insert(tree,d,location*2+1);
		if(xiangjian(tree+location*2+1,tree+location*2+2)==2)
		{
			if(d<(tree+location*2+1)->data)
			singleleftrotation(tree,location);
			else 
			doubleleftrightrotation(tree,location);
		}
	}
	else if(d>(tree+location)->data)
	{
		insert(tree,d,location*2+2);
		if(xiangjian(tree+location*2+2,tree+location*2+1)==2)
		{
			if(d>(tree+location*2+2)->data)
			singlerightrotation(tree,location);
			else
			doublerightleftrotation(tree,location);
		}
	}
	(tree+location)->height=max(tree+location*2+1,tree+location*2+2)+1;
}
void doublerightleftrotation(struct node *tree,int location)
{
	singleleftrotation(tree,location*2+2);
	singlerightrotation(tree,location);
}
void doubleleftrightrotation(struct node *tree,int location)
{
	singlerightrotation(tree,location*2+1);
	singleleftrotation(tree,location);
}

void singleleftrotation(struct node *tree,int location)
{
	
	*(tree+location*4+6)=*(tree+location*2+2);
	*(tree+location*4+5)=*(tree+location*4+4);
	*(tree+location*2+2)=*(tree+location);
	*(tree+location)=*(tree+location*2+1);
	*(tree+location*2+1)=*(tree+location*4+3);
	*(tree+location*4+3)=*(tree+location*8+7);
	*(tree+location*4+4)=*(tree+location*8+8);
	(tree+location*8+7)->data=0;
	(tree+location*8+8)->data=0;

	(tree+location*2+2)->height=max(tree+location*4+5,tree+location*4+6)+1;
	(tree+location)->height=max(tree+location*2+1,tree+location*2+2)+1;
}

void singlerightrotation(struct node *tree,int location)
{
	*(tree+location*4+3)=*(tree+location*2+1);
	*(tree+location*4+4)=*(tree+location*4+5);
	*(tree+location*2+1)=*(tree+location);
	*(tree+location)=*(tree+location*2+2);
	*(tree+location*2+2)=*(tree+location*4+6);
	*(tree+location*4+5)=*(tree+location*8+13);
	*(tree+location*4+6)=*(tree+location*8+14);
		(tree+location*8+13)->data=0;
		(tree+location*8+14)->data=0;	
	(tree+location*2+1)->height=max(tree+location*4+3,tree+location*4+4)+1;
	(tree+location)->height=max(tree+location*2+1,tree+location*2+2)+1;
}

int max(struct node *a,struct node *b)
{
	if(a->data==0&&b->data==0)
	return -1;
	if(a->height>b->height)
	return a->height;
	else
	return b->height;
}
int xiangjian(struct node *a,struct node *b)
{
	if(a->height==1&&b->data==0)
	return 2;
	else
	return a->height-b->height; 
}
