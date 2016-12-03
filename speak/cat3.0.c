#include <stdio.h>
struct Cat
{
	char name[20];	
	char colour[10];
	int weight;
};
int main()
{
	int i;
	struct Cat cats[5]= {{"Xiao-hua","white",20}, {"Xiao-ming","gray",10}, {"Xiao-li","Black",15}, {"Xiao-jian","Yellow",18}, {"Xiao-xiao","Green",13}};
	for (i=0; i<5; i++)
	{
		printf("猫的名字：%s,颜色：%s,重量：%dkg\n",cats[i].name,cats[i].colour,cats[i].weight);
	}
	return 0;
}
