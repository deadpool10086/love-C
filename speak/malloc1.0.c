#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	int *p; 
	a = 5;
	
	p = malloc(sizeof(int));
	scanf("%d",p);
	a = a + *p;
	free(p);
	
	a = a * a;
	
	printf("%d",a);
	
	return 0;

} 
