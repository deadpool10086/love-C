#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Word
{
	char eng[30],chi[30];
	char n;
};
int main(int argc, char *argv[]) {
	struct Word world;
	world.n='\n';
	FILE*p;
	if((p=fopen("D:\\input\\word.txt","w+"))==NULL)
	{
		printf("file error");
		exit(0);
	}
	while(1)
	{
		scanf("%s",world.eng);
		if(strcmp(world.eng,"exit")==0)
		break;
		scanf("%s",world.chi);
		fwrite(&world,sizeof(struct Word),1,p);
		
	}
	
	fclose(p);
	return 0;
}
