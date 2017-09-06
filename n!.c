#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("How many times do you want:");
	int n,i,m=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	 m=m*i;
	printf("number is %d",m); 
	system("pause");
	return 0;
}
