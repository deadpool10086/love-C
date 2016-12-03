#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	printf("%d",s(n));
	return 0;
}
int s(int n)
  {if(0==n)
   return 1;
   else
   return s(n-1)+n;
  }
