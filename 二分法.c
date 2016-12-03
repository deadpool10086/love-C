#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double x(double l,double d); 
	double l,d;
	printf("Enter the Numbers before you must determine the equation between them has a solution:");
	scanf("%lf%lf",&l,&d);
	printf("%lf",x(l,d));
	system("pause");
	return 0;
}
double f(double x)
  {double y;
   y=x*x-20*x-6;
   return y;
  }
double x(double l,double d)
  {double mid;
   while(abs(l-d)>0.0000006)
    {mid=(l+d)/2;
     if(f(l)*f(mid)<0)
      d=mid;
     else
	 l=mid; 
	}
   return l;
  }  
