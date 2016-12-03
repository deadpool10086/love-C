#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int boy=0,gril=0,i;
	for(i=1;i<=N;i++)
	 {if(rand()<=RAND_MAX/2)
	   boy=boy+1;
	  else
	  {gril=gril+1;
	   if(rand()<=RAND_MAX/2)
	   boy=boy+1;
	   else
	   gril=gril+1;
	   } 
	 }
	printf("%d  %d\n",boy,gril);
	system("pause"); 
	return 0;
}
