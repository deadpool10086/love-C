#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gcb_1(int a, int b)
{


	int n;
	int r;

	if(a==0 && b==0)
	return -1;
	n = b;	
	while(b > 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int gcb_2(int a, int b)
{
	int n;
	if(a==0 && b==0)
		return -1;
	if(a < b)
	{
		n = a;
		a = b;
		b = n;
	}
	n = b;
	while(n > 0)
	{
		if(a % n == 0 && b % n == 0)
			break;
		else
			n--;
	}
	if(n == 0)
		return a;
	else
		return n;
}
int gcb_3(int a, int b)
{
	if(a==0 && b==0)
		return -1;

	if(a != 0 && b != 0)
	{
		while(1)
		{
			if(a > b)
				a = a - b;
			else if(a < b)
				b = b - a;
			else
				break;
		}
	}
	if(a == 0)
	a = b;
	return a;
}

void tuff(int *a,int *b,int n)
{
	
	int i;
	for(i=0; i<n; i++)
	{
		a[i] = rand();
		b[i] = rand();
	}

}
int main()
{
	int *a;
	int *b;
	int n;
	int num = 100;
	clock_t start,finish;
	double duration;
	srand((unsigned)time(NULL));

	for( ;num <= 1000000; num*=10)
	{
		a = (int *)malloc(sizeof(int)*num);
		b = (int *)malloc(sizeof(int)*num);
		tuff(a,b,num);

		start = clock();
		n = num;
		while(n > 0)
		{
			n--;
			gcb_1(a[n],b[n]);
		}
		finish = clock();
		duration = (double)(finish - start) /CLOCKS_PER_SEC;
		printf("’∑◊™œ‡≥˝:%d times spend time is %f\n",num,duration);

		start = clock();
		n = num;
		while(n > 0)
		{
			n--;
			gcb_2(a[n],b[n]);
		}
		finish = clock();
		duration = (double)(finish - start) /CLOCKS_PER_SEC;
		printf("÷∏ˆ≤‚ ‘:%d times spend time is %f\n",num,duration);
		
		start = clock();
		n = num;
		while(n > 0)
		{
			n--;
			gcb_3(a[n],b[n]);
		}
		finish = clock();
		duration = (double)(finish - start) /CLOCKS_PER_SEC;
		printf("ª•œ‡ºı:%d times spend time is %f\n\n",num,duration);
		free(a);
		free(b);
	}

	

	getchar();
//	printf("%d\n",gcb_1(b,a));
//	printf("%d\n",gcb_2(b,a));
//	printf("%d\n",gcb_3(b,a));

	return 0;
}


