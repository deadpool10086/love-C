#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define JUMPPOW 4
#define CRONUM 20
#define UFLOG 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int queue[20],sofq=0,eofq=0;

int gbfs(int *p,int s);
void add(int n);
void out(int *p);

int main(int argc, char *argv[]) {
	int a,b,i;
	srand((unsigned)time(NULL));
	int crocodile[CRONUM];
	for(i=0;i<CRONUM;i++)
	{
		do
		{
			a=rand()%98+1;
			b=rand()%98+1;
		}while((a>=48&&a<=51)&&(b>=48&&b<=51));
		crocodile[i]=a*100+b;
	}
	for(i=45;i<55;i++)                           //这里初始化007第一跳，因为有小岛他可以跳的范围大一点。 
	{
		for(a=45;a<55;a++)
		for(b=0;b<CRONUM;b++) 
		if(crocodile[b]==i*100+a)
		if(gbfs(crocodile,i*100+a))
		{
			printf("yes");
			return 0;
		}
	}
	return 0;
}
int gbfs(int *p,int s)								//这里是一个广度优先搜索 
{
	int i,j,temp,i2;
	add(s);
	while(eofq!=sofq)
	{
		out(&s);
		for(i=0;i<CRONUM;i++)
		{
			if(p[i]==s)
			p[i]+=UFLOG;								//值得注意的是我用万位来标志是否已经遍历 
		}
		for(i=-JUMPPOW;i<=JUMPPOW;i++)
		{
			temp=sqrt(JUMPPOW*JUMPPOW-i*i);	
			for(j=-temp;j<=temp;j++)
			{	
				if(s/100+i<=0||s/100+i>=99||s%100+j<=0||s%100+j>=99)
				return 1;
				else 
				for(i2=0;i2<CRONUM;i++)
				{
					if(p[i2]==s+i*100+j)
					add(s+i*100+j);
				}
				
			}
		}
	}
	return 0;
}
void add(int n)
{
	if(sofq-eofq==1||eofq-sofq==19)
	{
		printf("queue has fulled");
		exit(0);
	}
	else
	{
		queue[eofq++]=n;
		if(eofq==20)
		eofq=0;
	}
}
void out(int *p)
{
	*p=queue[eofq++];
	if(eofq=20)
	eofq=0;
}

