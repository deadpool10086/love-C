#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int wnos(char *p);
	char str[30];
	printf("Please input a string:\n");
	int i=0;
	do{
		*(str+i++)=getchar();
	}
	while(*(str+i-1)!='\n'&&i<30);
	*(str+i-1)='\0';
	printf("%d",wnos(str));
	return 0;
}
int wnos(char *p){
	int i;
	for(i=0;*p!='\0';p++){
		i++;
	}
	return i;
}
