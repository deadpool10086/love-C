#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a=0,b=0,c=0;
void divide(int n);
void juge(int n);
void solve(void);
void sort0(int *p); 
void sort1(int *p);
int main(int argc, char *argv[]) {
	int num,i;
	printf("请输入一个三位数：");
	scanf("%d",&num); 
	divide(num);
	juge(num);
	solve();
	int data0[10],data1[10];
	srand((unsigned)time(NULL));
	data0[0]=data1[0]=a;
	data0[1]=data1[1]=b;
	data0[2]=data1[2]=c;
	for(i=3;i<10;i++)
	{
		data0[i]=data1[i]=rand()%100;
	}
	sort0(data0); 
	sort1(data1);
	return 0;
}
void divide(int n)
{
	c=n%10;
	n/=10;
	b=n%10;
	n/=10;
	a=n%10;
	printf("%d\t%d\t%d\t",a,b,c);
}
void juge(int n)
{
	int x;
	x=(int)(pow(a,3)+pow(b,3)+pow(c,3));
	if(x==n)
	printf("是水仙花数。\n");
	else
	printf("不是水仙花数。\n"); 
}
void solve(void)
{
	double d;
	d=pow(b,2)-4*a*c;
	if(d<0)
	printf("无解；\n");
	else if(d==0)
	printf("有唯一一根为：X=%f\n",-b/(2*a));
	else
	printf("有两根为：X1=%f\tX2=%f\n",(-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a));
}
void sort0(int *p)
{
	int t,i,j;
	for(i=0;i<10;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("\n");
	for(i=1;i<10;i++)
	{
		t=p[i];
		for(j=i;j>0;j--)
		{
			if(t>=p[j-1])
			break;
			else
			p[j]=p[j-1];
		}
		p[j]=t;
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("\n");
}
void sort1(int *p)
{
	int i=0,j,t;
	for(i=0;i<10;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("\n");

	for(i=1;i<10;i++)
		for(j=0;j<10-1;j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t; 
			}
		}
	for(i=0;i<10;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("\n");
}
