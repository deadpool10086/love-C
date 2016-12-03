#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,s;
	printf("Please sent a number:");
	scanf("%d",&s);
	for(i=1;i<=s;i++)
	{for(j=1;j<=s;j++)
	 {if(j<=s-i)
	   printf("  ");
	  else 
	   printf("* "); 
	 }
	 printf("\n");
	}
	system("pause");
	return 0;
}
