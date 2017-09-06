#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,n,l,k;
	char c='A';
	scanf("%d",&n);
	for(i=1;i<=2*n-1;i++)
	 {for(j=1;j<=abs(n-i)+1;j++) printf("*");
	  for(l=1;l<=2*(n-abs(n-i))-1;l++)
	  {printf("%c",c);
	   c++; 
	   if(c=='Z'+1)
	   c='A';
	  }
	  for(j=1;j<=abs(n-i)+1;j++)  printf("*");
	  printf("\n");
	 }
	return 0;
}
