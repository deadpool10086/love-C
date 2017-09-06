#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int i,bwin,hwin;
	for(i=1;i<=N;i++)
	{if(jieguo(0)==1)
	 bwin++;
	}
	for(i=1;i<=N;i++)
	{if(jieguo(1)==1)
	 hwin++;
	}
	printf("%d\n%d",bwin,hwin); 
	system("pause");
	return 0;
}
int jieguo(int n)
{int b[3]={0,0,0};
 int ture,hand,del;
 ture=rand()%3;
 b[ture]=1;
 hand=rand()%3;
 do
 del=rand()%3;
 while(del==hand||del==ture);
 if(n)
  hand=3-del-hand;
 if(b[hand]==1)
  return 1;
  return 0; 
}
