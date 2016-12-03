#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char name1[30],name2[30],name3[30];
	void compare(char **p);
	int i;
	char *a[3];
	a[0]=name1;
	a[1]=name2;
	a[2]=name3;
	for(i=0;i<3;i++)
	  gets(*(a+i));
	compare(a); 
	for(i=0;i<3;i++)
	  puts(*(a+i));
	return 0;
}
void compare(char **p)
{   void swith(char **a,char **b);
    if(strcmp(*p,*(p+1))>0)  swith(p,(p+1));
    if(strcmp(*p,*(p+2))>0)   swith(p,(p+2));
	if(strcmp(*(p+1),*(p+2))>0)   swith((p+1),(p+2));
}
void swith(char **a,char **b)
{   char *temp;
    temp=*a;
    *a=*b;
    *b=temp;
    
}
