#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x=500;
	for(;!(x%5==3&&x%7==6&&x%11==4)||x>=1000;x++)
	 {
	 }
	printf("%d\n",x);
	system("pause");
	return 0;
}
