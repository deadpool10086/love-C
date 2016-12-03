#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,j,l;
	char c='A';
	scanf("%d",&n);
	for(i=1;i<=2*n-1;i++)
	 {for(j=1;j<=abs(n-i);j++)
	  {printf(" ");}
	  for(l=1;l<=2*n-2*abs(n-i)-1;l++)
	  printf("%c",c+i-1);
	  printf("\n");
	 }
	system("pause"); 
	return 0;
}
