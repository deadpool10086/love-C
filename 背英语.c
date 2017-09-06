#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chi[50],eng[20],anser[20];
	FILE*fp;
	if((fp=fopen("D:\\input\\word.txt","r"))==NULL)
	{
		printf("file error");
		exit(0);
	}
	while(1)
	{
		fscanf(fp,"%s%s",eng,chi);
		if(strcmp(eng,"stop")==0)
		break;
		printf("%s\n",chi);
		do
		scanf("%s",anser);
		while(strcmp(eng,anser)!=0);
	}
	fclose (fp);
	return 0;
}
