#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=1,b=2,n,t,i;
	double s=0;
	printf("please input how many items:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {s=s+(double)b/a;
	  t=b,b=a+b,a=t;
	  }
	printf("The number is %lf\n",s);
	system("pause"); 
	return 0;
}
