#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int y,leap;
	printf("please input a year:",&y);
	scanf("%d",&y);
	if (y%4!=0)
	{leap=0;}
	else if(y%100!=0)
	{leap=1;}
	else if(y%400==0)
	{leap=1;}
	else
	{leap=0;}
	if(leap)
	{printf("Yes\n");}
	printf("No\n");
	system("pause");
	return 0;
}
