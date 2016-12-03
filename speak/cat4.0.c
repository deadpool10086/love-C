#include <stdio.h>
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
	struct Cat cats[5]= {{"Xiao-hua","white",20}, {"Xiao-ming","gray",10}, {"Xiao-li","Black",15}, {"Xiao-jian","Yellow",18}, {"Xiao-xiao","Green",13}};
	struct Cat * head = NULL;
	
	head = &cats[0];
	cats[0].next = &cats[1];
	cats[1].next = &cats[2];
	cats[2].next = &cats[3];
	cats[3].next = &cats[4];
	cats[4].next = NULL;
	
		while(head != NULL)
	{
		printf("猫的名字：%s,颜色：%s,重量：%dkg\n",head->name,head -> colour,head ->weight);
		head = head->next;
	}
	return 0;
}
