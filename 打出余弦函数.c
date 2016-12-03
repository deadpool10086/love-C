#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double y;
	int x,i;
	for(y=1;y>=-1;y-=0.2)
	{
		x=acos(y)*10;
		for(i=1;i<x;i++)
		printf(" ");
		printf("*");
		for(;i<62-x;i++)
		printf(" ");
		printf("*\n");
	}
	return 0;
}
