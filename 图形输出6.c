#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,k,n;
	printf("please input a number:");
	scanf("%d",&n);
	for(i=n-1;i>-n;i--)
	{
		for(j=0;j<abs(i);j++)
		printf(" ");
		for(k=0;k<2*(n-abs(i))-1;k++)
		printf("*");
		printf("\n");
	}
	return 0;
}
