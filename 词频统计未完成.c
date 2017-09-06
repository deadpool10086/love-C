#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int getword(FILE *fp,char *word);
int getkey(char *p,int l); 

int main(int argc, char *argv[]) {
	FILE *fp;
	char word[20];
	int length,key;
	if((fp=fopen("d:\\input\\word.txt","r"))==NULL)
	{
		printf("file error");
		exit(0);
	}
	while(!feof(fp))
	{
		length=getword(fp,word);
		printf("%s\n",word);
		
	}
	return 0;
}
int getword(FILE *fp,char *word)
{
	fscanf(fp,"%s",word);
	int n=0;
	while(word[n]!=0)
	n++;
	return n;
}

int getkey(char *p,int l)
{
	
}
