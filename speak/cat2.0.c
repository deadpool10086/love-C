#include <stdio.h>

int main ()
{
	int i;
	int weight[5] = {20,10,15,18,13};
	char colour[5][20] = {"Xiao-hua","Xiao-ming","Xiao-li","Xiao-jian","Xiao-xiao"};
	char name[5][20] = {"white","gray","Black","Black","Green"}; 

	for (i=0; i<5; i++)
	{
		printf("è�����֣�%s,��ɫ��%s,������%dkg\n",name[i],colour[i],weight[i]);
	}
	return 0;
} 
