#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d;
	printf("please input a three digits:");
	scanf("%d",&a);
	b=a/100;
	c=a%100/10;
	d=a%100%10;
	a=d*100+c*10+b;
	printf("%d\n",a);
	system("pause");
	return 0;
}
