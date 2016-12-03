#include <stdio.h>

int main ()
{
	char name1[20] = "Xiao-hua";
	char colour1[10] = "white";
	int weight1 = 20;
	
	char name2[20] = "Xiao-ming";
	char colour2[10] = "gray";
	int weight2 = 10;
	
	char name3[20] = "Xiao-li";
	char colour3[10] = "Black";
	int weight3 = 15;
	
	char name4[20] = "Xiao-jian";
	char colour4[10] = "Yellow";
	int weight4 = 18;
	
	char name5[20] = "Xiao-xiao";
	char colour5[10] = "Green";
	int weight5 = 13;
	
	printf("猫的名字：%s,颜色：%s,重量：%dkg\n",name1,colour1,weight1);
	printf("猫的名字：%s,颜色：%s,重量：%dkg\n",name2,colour2,weight2);
	printf("猫的名字：%s,颜色：%s,重量：%dkg\n",name3,colour3,weight3);
	printf("猫的名字：%s,颜色：%s,重量：%dkg\n",name4,colour4,weight4);
	printf("猫的名字：%s,颜色：%s,重量：%dkg\n",name5,colour5,weight5);
	return 0;
} 
