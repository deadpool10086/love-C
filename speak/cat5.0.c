#include <stdio.h>
#include <stdlib.h>
struct Cat
{
	char name[20];	
	char colour[10];
	int weight;
	struct Cat *next; 
};
int main()
{
	int i;
	struct Cat * head = NULL;
	struct Cat * temp = NULL;
	
	for(i=0; i < 5; i++)
	{
		temp = malloc(sizeof(struct Cat));
		printf("请输入猫的名字 颜色 重量:");
		scanf("%s%s%d",temp->name,temp->colour,&temp->weight);
		temp->next = head;
		head = temp;
	 } 

	
	while(head != NULL)
	{
		printf("猫的名字：%s,颜色：%s,重量：%dkg\n",head->name,head -> colour,head ->weight);
		head = head->next;
	}

	return 0;
}
