#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,sum=0,max;
	printf("please input a number");
	scanf("%d",&x);
	max=x;
	while(x!=1)
	 {if(x%2==1)
	  x=x*3+1;
	  else
	  x=x/2;
	 if(max<=x)
	  max=x;
	 sum++;  
	 }
	printf("需要%d步，最大值为%d",sum,max); 
	system("pause"); 
	return 0;
}
