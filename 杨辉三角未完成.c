#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("please in put xy point as \"x,y\":");
	int x,y;
	scanf("%d,%d",&x,&y);
	x=yanghui(x,y);
	printf("%d",x);
	system("pause");
	return 0;
}
int yanghui(int x,int y)
{
	if(y==1||y==x)
	return 1;
	else
	return (yanghui(x-1,y-1)+yanghui(x-1,y));
}
