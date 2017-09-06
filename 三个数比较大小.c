#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,tmp;
	printf("please input three number:");
	scanf("%d%d%d",&a,&b,&c);
	 {tmp=a;
	  a=b;
	  b=tmp;
	 }
	if(a<c)
	 {tmp=a;
	  a=c;
	  c=tmp;
	 }
	if(b<c)
	 {tmp=b;
	  b=c;
	  c=tmp;
	 }
	printf("%d %d %d\n",a,b,c);
	system("pause");
	return 0;
}
