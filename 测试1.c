#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	int p;
	scanf("%d",&p);
    while((c=getchar())!='\n')
	   {
	    if(c>='a'&&c<='z')
	     c='a'+(c-'a'+3)%26;
	    else if(c>='A'&&c<='Z')
		 c='A'+(c-'A'+3)%26;
	    putchar(c);}
	return 0;
}
