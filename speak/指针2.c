#include <stdio.h>

int main()
{
	int a;
	int *p; 
	p = &a;
	scanf("%d",&a);

	printf("\n%d",a);
	
	*p = *p + 1;
	printf("\n%d",a);
	
	return 0;
 } 
