#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char n;
	scanf("%c",&n);
	if(n>=0&&n<=9)
	{printf("This is a number\n");}
	else if(n>='a'&&n<='z')
	{printf("This is a lowercase letter\n");}
	else if(n>='A'&&n<='Z')
	{printf("This is a capital letter\n");}
	else
	{printf("This is nothing\n");}
	system("pause");
	return 0;
}
