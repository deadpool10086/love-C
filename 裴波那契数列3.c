#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	printf("%d",pbnq(n));
	return 0;
}
int pbnq(int s)
   {if(1==s||2==s)
    return 1;
    else
    return pbnq(s-1)+pbnq(s-2);
   }
