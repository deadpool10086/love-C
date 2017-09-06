#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	void sort(int *p,int s,int e);
	void search(int *p,int n,int m);
	int i,m=1,nums[100];
	srand(time(NULL));
	for(i=1;i<100;i++)
		nums[i]=rand();
	sort(nums,1,99);
	for(m=1;m<6;m++)
		printf("     %-5d",m);
	printf("\n");
	for(i=1,m=1;i<100;i++)
		{	
			if(i%5==0||i==1)
			printf("\n%2d  ",m++);
			printf("%-10d",nums[i]);
		}
	printf("\nPlease input the number which you want to search:");
	scanf("\n%d",&i);
	search(nums,99,i);
	return 0;
}
void sort(int *p,int s,int e)
{
	int star,end;
	star=s;
	end=e;
	*p=p[s];
	while(s<e)
	{
		while(s<e&&p[0]<p[e])
			e--;
		if(s<e)
			p[s]=p[e];
		while(s<e&&p[0]>=p[s])
			s++;
		if(s<e)
			p[e]=p[s];
	}
	p[e]=p[0];
	if(star<s)
		sort(p,star,s-1);
	if(end>e)
		sort(p,s+1,end);
}
void search(int *p,int n,int m)
{
	int cut,i=1;
	while(1)
	{
		cut=(i+n)/2;
		if(m==p[cut])
		{
			printf("%d",cut);
			return ;
		}
		else if(m>p[cut])
			i=cut+1;
		else
			n=cut-1;
		if(n<i)
			{
				printf("errior");
				return ;
			}
	}
	
}
