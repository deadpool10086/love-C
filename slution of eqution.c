#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a,b,c,x1,x2,m;
	printf("please input a b c the eqution of:\n");
	scanf("%f%f%f",&a,&b,&c);
	m=b*b-4*a*c;
	if(m>=0)
	  {x1=(sqrt(m)-b)/(2*a);
	   x2=(-sqrt(m)-b)/(2*a);
	   printf("Solution of the equation is\nx1=%f  x2=%f",x1,x2);
	  }
	  else
	    printf("This eqution has no solution\n");
	return 0;
}
