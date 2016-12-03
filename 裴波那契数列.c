#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=3,n;
	unsigned long int sum=1,a=1,b=0,t;
	printf("please input how many months you want:");
	scanf("%d",&n);
	while(i<=n)
	  {sum=sum+a;
	  t=a,a=a+b,b=t;
	  i++;
	  }
	printf("The number of rabbits is %ld\n",sum*2);
	system("pause");
	return 0;
}
