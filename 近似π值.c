#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int sum=0,i;
	double x,y;
	srand((unsigned)time(NULL));
	for(i=1;i<=N;i++)
	 {x=(double)rand()/RAND_MAX;
	  y=(double)rand()/RAND_MAX;
	  if(x*x+y*y<=1)
	   sum=sum+1; 
	 }
	printf("%lf\n",(double)sum/N*4);
	system("pause");
	return 0;
}
