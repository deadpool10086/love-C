#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Zhan
{
	char c;
	struct Zhan *last;
}; 
int main(int argc, char *argv[]) {
	struct Zhan *zhan=NULL;
	void push(struct Zhan**p);
	void out(struct Zhan**p);
	push(&zhan);
	out(&zhan);
	return 0;
}
void push(struct Zhan**p)
{
	struct Zhan *temp;
	if(*p==NULL)
		{
			*p=malloc(sizeof(struct Zhan));
			scanf("%c",&(**p).c);
			(**p).last=NULL;
		}
	else
	{
		*p=malloc(sizeof(struct Zhan));
		scanf("%c",&(**p).c);
		temp=*p;
		(**p).last=temp;
	}
}
void out(struct Zhan**p)
{
	struct Zhan*temp;
	if(*p==NULL)
		{
			printf("empty");
			exit(0);
		}
	else
	{
		printf("%c",(**p).c);
		temp=*p;
		*p=(**p).last;
		free(temp);
	}
}
