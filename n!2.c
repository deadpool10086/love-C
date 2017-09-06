#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	printf("%d",jiecheng(n));
	return 0;
}
int jiecheng(int s)
  {if(1==s) return 1;
   else
   return jiecheng(s-1)*s;
  }
