#include <stdio.h>
#include <stdlib.h>

void initialize(int d[10][2]);
int find(int (*p)[2],int x);
void uni(int (*p)[2],int x,int y);

int main(int argc, char *argv[]) {
	int set[10][2],i;
	initialize(set);
	uni(set,1,2);
	uni(set,2,4);
	uni(set,3,5);
	uni(set,4,7);
	uni(set,5,8);
	uni(set,6,9);
	uni(set,6,10);
	if(find(set,2)==find(set,7))
	printf("1");
	if(find(set,6)==find(set,10))
	printf("2");
	return 0;
}
void initialize(int d[10][2])
{
	int i;
	for(i=0;i<10;i++)
	{
		d[i][0]=i+1;
		d[i][1]=-1;
	}
}
int find(int (*p)[2],int x)
{
	int i;
	for(i=0;i<10&&**(p+i)!=x;i++)
	if(i>=10)  return -1;
	for(;*(*(p+i)+1)>-1;i=*(*(p+i)+1));
	return i;
}
void uni(int (*p)[2],int x,int y)
{
	int root1,root2,temp;
	root1=find(p,x);
	root2=find(p,y);
	if(*(*(p+root1)+1)>*(*(p+root2)+1))
	{
		root1=temp;
		root2=root1;
		root1=temp;
	}
	*(*(p+root1)+1)+=*(*(p+root2)+1);
	*(*(p+root2)+1)=root1;
}
