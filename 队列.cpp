#include <stdio.h> 
int main ()
{
	int nums[20];
	int *ps,*pe;
	pe=ps=nums;
	int n,m;
	do
	{
		printf("please input <1>add <2>out <0>quit:");
		scanf("%d",&m);
		if(m==1)
		{
			if(ps-pe==1||pe-ps==19)
			{
				printf("full\n");
				continue;
			}
			else
			{
				scanf("%d",&n);
				if(pe!=nums+19)
				{
					*pe=n;
					pe++;
				}
				else
				{
					*pe=n;
					pe=nums;
				}
			}
		}
		else if(m==2)
		{
			if(ps==pe)
			{
				printf("empty\n");
				continue;
			}
			else
			{
				if(ps!=nums+19)
				{
					printf("%d\n",*ps);
					ps++;
				}
				else
				{
					printf("%d\n",*ps);
					ps=nums;
				}
			}
		}
	}while(n!=10086);
	return 0;
}
