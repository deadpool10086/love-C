#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sum=0;
int main(int argc, char *argv[]) {
	int ture,i=1;
	void jieguo(int ture);
	srand((unsigned)time(NULL));
	for(ture=rand()%3;i<=N;i++)
	 jieguo(ture);
	printf("%lf",(double)sum/N); 
    return 0;
}
void jieguo(int ture)
 {int chiose,del;
  chiose=rand()%3;
  for(del=rand()%3;del==chiose||del==ture;)
    {del=rand()%3;}
  if  (chiose==ture)  sum++;
 }
