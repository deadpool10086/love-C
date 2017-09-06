#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,y,z;
	for(x=1;x<10;x++)
	for(y=1;y<10;y++)
	for(z=1;z<10;z++)
	{
		if(z%2==1&&x%2==1)
		continue;
		if((x*100+y*10+z)*(y*10+x)==10248)
		printf("x=%d,y=%d,z=%d\n",x,y,z);
	}
	system("pause");
	return 0;
}
