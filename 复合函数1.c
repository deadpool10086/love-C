#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double mypower(double x,int n)
  {int i;
   double y=1.0;
   for(i=0;i<n;i++)
   y=y*x;
   return y; 
  }
int main(int argc, char *argv[]) {
	printf("%lf\n",mypower(5,2));
	printf("%lf",mypower(3,5));
	return 0;
}

