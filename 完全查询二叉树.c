#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void quicksort(int *data, int left, int right);
void insert_sort(int *data,int n);
void swap(int *a,int *b);
int middle(int *l,int *r,int *m);
void quicksort(int *data, int left, int right);
void quick_sort(int *data,int n);
void summon(int *soudata,int oldl,int oldr,int newr,int *newtree);
int getleftlength(int n);

int main(int argc, char *argv[]) {
	int soudata[10000],sum=10000;
	int newdata[10000];
	srand((unsigned)time(NULL));
	int i;
	for(i=0;i<sum;i++)
		{soudata[i]=rand();}
	quick_sort(soudata,sum);
	summon(soudata,0,sum-1,0,newdata);
	for(i=0;i<300;i++)           //查看结果 
	{printf("%d\t",newdata[i]);}
	printf("%d",(newdata[0]+newdata[9999])/2);
	return 0;
}

void summon(int *soudata,int oldl,int oldr,int newr,int *newtree)
{
	int n,l;
	n=oldr-oldl+1;
	if(n==0)
	return;
	l=getleftlength(n);
	newtree[newr]=soudata[oldl+l];
	summon(soudata,oldl,oldl+l-1,newr*2+1,newtree);
	summon(soudata,oldl+l+1,oldr,newr*2+2,newtree);
}
int getleftlength(int n)
{
	int plies,square=1,leave=0,m=0,i=0;
	for(plies=0,m=1;square<n;plies++)
	{
		m*=2;
		square=square+m; 
	}
	leave=square-n;
	m=m/2;
	if(leave-m>0)
	leave-=m;
	square=(square-1)/2-leave;
	return square;
}

void quick_sort(int *data,int n)
{
	quicksort(data,0,n-1);
}

void quicksort(int *data, int left, int right)
{
	int privot,l,r;
	if(right-left+1<30)
	{
		privot=middle(data+left,data+right,data+(left+right)/2);
		l=left;r=right;
		while(1)
		{
			while(data[++l]<privot)
			{ }
			while(data[--r]>privot)
			{ }
			if(l>r)
			break;
			else
			swap(data+r,data+l);
		}
		swap(data+l,data+right-1);
		quicksort(data,left,r);
		quicksort(data,l+1,right);
	}
	else
	{
		insert_sort(data+left,right-left+1);
	}
}

void insert_sort(int *data,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=data[i];
		for(j=i;data[j-1]>temp&&j>0;j--)
			data[j]=data[j-1];
		data[j]=temp;
	}
}
int middle(int *l,int *r,int *m)
{
	if(*l>*r)
	swap(l,r);
	if(*l>*m)
	swap(l,m);
	if(*m>*r)
	swap(m,r);
	swap(m,r-1);
	return *(r-1);
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*b=*a;
	*a=temp; 
}
