#include <stdio.h>
#include <stdlib.h>
#define N 10 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	void print(float (*p)[2],int n);
	void search(float (*p)[2],int n);
	int charu(float (*p)[2],int n);
	int shanchu(float (*p)[2],int n);
	int i,n;
	float sl[N][2];
	float (*p)[2];
	p=sl;
	printf("Please input your information:\"changshu,zhishu\"\n");
	for(i=0;i<N;i++)
	{scanf("%f,%f",*(p+i),*(p+i)+1);
	if(**(p+i)==0)
		break;
	}
	printf("this shuilie have %d part\n",i);
	do
	{
		printf("what do you want <1>print <2>search <3>charu <4>shanchu <0>quit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:print(p,i);break;
			case 2:search(p,i);break;
			case 3:i=charu(p,i);break;
			case 4:i=shanchu(p,i);break;
		}
	}while(n!=0);
	
	return 0;
}
void print(float (*p)[2],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-7.2f,%-5.0f\n",**(p+i),*(p[i]+1));
	}
}
void search(float (*p)[2],int n)
{
	int i;
	printf("Please in put you numbe:");
	scanf("%d",&i);
	printf("%-7,2f,%-5.0f",**(p+i),*(p[i]+1));
}
int charu(float (*p)[2],int n)
{
	int i,j;
	j=n;
	float cs,zs;
	if(n>=N)  printf("sorry it's full");
	else
	printf("whith number do you want insert before it:");
	scanf("%d",&i);
	printf("Please in put your data:");
	scanf("%f,%f",&cs,&zs);
	if(i>N) 
	{
		printf("error");
		return n;
	}
	else if(i=N) **(p+j)=cs,*(p[j]+1)=zs;
	else
	for(;j>=i;j--)
	**(p+j)=**(p+j-1),*(p[j]+1)=*(p[j-1]+1);
	**(p+j)=cs,*(p[j]+1)=zs;
	n=n+1;
	print(p,n);
	return n;
}
int shanchu(float (*p)[2],int n)
{
	int i;
	printf("whitch one do you want delete");
	scanf("%d",&i);
	if(i>n) 
	{
		printf("error");
		return n;
	}
	else if(i=n) **(p+i-1)=0,*(p[i-1]+1)=0;
	else for(;i<n;i++)
	{
		**(p+i-1)=**(p+i);
		*(p[i-1]+1)=*(p[i]+1);
	}
	n=n-1;
	print(p,n);
	return n;
	
}
