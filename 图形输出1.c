#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,s;
	printf("Please sent a number:");
	scanf("%d",&s);
	s=5;
	for(i=1;i<=s;i++)
	{for(j=1;j<=s;j++)
	 printf("* ");
	 printf("\n");
	}
	
	getchar(); 
	system("pause");
	return 0;
}
