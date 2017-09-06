#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[17];
	int i=0,j;
    gets(str);
	char new[17];
	char tmp;
   for(i=0;i<=16;i++)
   {new[16-i]=str[i];
    new[16]=tmp;
    for(j=16;j>=1;j--)
     {new[j]=new[j-1];}
    new[16-i]=tmp; 
   }
   int sum=0;
	for(i=0;i<=16;i++)
	 {printf("%c",new[i]);
	  sum++;}
	  printf("%d",sum);
	return 0;
}

