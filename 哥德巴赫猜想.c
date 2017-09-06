#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int isprime(int n);
	int sum=0,n,x1,x2;
	scanf("%d",&n);
	for(x1=1,x2=n-1;x1<=x2;x1++,x2--)
	  {if(isprime(x1)&&isprime(x2))
	     {printf("%d=%d+%d\n",n,x1,x2);
	   sum++;}
	  } 
	 printf("This number has %d kinds of solutions\ns",sum); 
	system("pause");  
	return 0;
}
int isprime(int n)
  {int i,y;
   for(i=2;i<=sqrt(n);i++)
    if(n%i==0)
      {y=0;return y;}
    y=1;
	return y;  
  }
