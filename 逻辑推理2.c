#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	for(a=1;a<=3;a++)
	  for(b=1;b<=3;b++)
	   for(c=1;c<=3;c++)
	    {if(1==a)
	     continue;
	     if(3==a)
	     continue;
	     if(3==c)
	     continue;
	     if(a!=b&&b!=c&&c!=a){;}
	     else continue;
	     printf("%d %d %d",a,b,c);
		}
	   
	return 0;
}
