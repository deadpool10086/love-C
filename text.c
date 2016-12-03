#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long sum,x,i;
	for(i=1;sum<100;i++)
	 {x=i,sum=0;
	  while(x!=1)
	  {if(x%2==1)
	  x=x*3+1;
	  else
	  x=x/2;
	  sum++;
	  }
	 }
	printf("%ld %ld\n",sum,i-1);
	return 0;
}
