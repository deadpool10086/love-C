#include <stdio.h>
#include <math.h>
int main()
{
	int n,i;
	printf("Plesase in put a number:"); 
	scanf("%d",&n);
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			printf("%d  no",i);
			return 0;
		}
	printf("yes");
	return 0;
}
