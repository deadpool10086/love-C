#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,y,z;
	for(x=1;x<=3;x++)
	 for(y=1;y<=3;y++)
	  for(z=1;z<=3;z++)
	   {if(x!=1&&x!=3&&z!=3&&x!=y&&y!=z&&z!=x) 
	    printf("x=%d y=%d z=%d\n",x,y,z);
	    
	   }
	system("pause");   
	return 0;
}
