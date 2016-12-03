#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct infor
{
	char name[20];
	int age;
}; 


int main(int argc, char *argv[]) {
	struct infor someone;
	printf("请输入一个名字和年纪：");
	scanf("%s%d",someone.name,&someone.age);
	int star,end,s1=0,s2=0,i;
	while(1)
	{
		star=time(NULL);
		printf("%d  ",star);
		if(star!=end)
		{
			system("cls");
			for(i=0;i<s1;i++)
			{
				printf("\n");
			}
			s1++;
			s1=s1%30;
			for(i=0;i<s2;i++)
			{
				printf(" ");
			}
			s2++;
			s2=s2%100;
			printf("%s:%d",someone.name,someone.age);
		}
		end=time(NULL);
		printf("%d",end);
	}
	return 0;
}
