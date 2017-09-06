#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int isprime(int n);
	int n;
	printf("Please input a number:");
	scanf("%d",&n);
	if(isprime(n))
	 printf("Yes");
	else
	 printf("No"); 
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
