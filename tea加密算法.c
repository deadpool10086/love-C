#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num_rounds 32
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void encipher(unsigned int v[],unsigned int key[4]);
void decipher(unsigned int v[],unsigned int key[4]);

int main(int argc, char *argv[]) {
	while(argc!=5)
	{
		printf("\n Usage:%s e(encipher) password SourceFileName OutFileName",argv[0]);
		printf("\n Usage:%s d(decipher) password SourceFileName OutFileName",argv[0]);
		return 0;
	}
	char password[100]={0};
	strcpy(password,argv[2]);
	FILE*fpin,*fpout;
	fpin=fopen(argv[3],"rb");
	fpout=fopen(argv[4],"wb");
	if(fpin!=NULL&&fpout!=NULL)
	{
		while(!feof(fpin))
		{
			unsigned int msg[2]={0};
			if(fread(msg,1,8,fpin)==0)
				break;
			if(argv[1][0]=='e')
				encipher(msg,(unsigned int *)password);
			else if(argv[1][0]=='d')
				decipher(msg,(unsigned int *)password);
			else
			{
				printf("Don't unstan\"%s\"",password);
				exit(0);
			}
			fwrite(msg,1,8,fpout);
		}
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
void encipher(unsigned int v[],unsigned int key[4])
{
	unsigned int i;
	unsigned int v0=v[0],v1=v[1],sum=0,delta=0x9E3779B9;
	for(i=0;i<num_rounds;i++)
	{
		v0+=(((v1<<4)^(v1>>5))+v1)^(sum+key[sum&3]);
		sum+=delta;
		v1+=(((v0<<4)^(v0>>5))+v0)^(sum+key[(sum>>11)&3]);
	}
	v[0]=v0;
	v[1]=v1;
}
void decipher(unsigned int v[],unsigned int key[4])
{
	unsigned int i;
	unsigned int v0=v[0],v1=v[1],delta=0x9E3779B9,sum=delta*num_rounds;
	for(i=0;i<num_rounds;i++)
	{
		v1-=(((v0<<4)^(v0>>5))+v0)^(sum+key[(sum>>11)&3]);
		sum-=delta;
		v0-=(((v1<<4)^(v1>>5))+v1)^(sum+key[sum&3]);
	}
	v[0]=v0;
	v[1]=v1;
}
