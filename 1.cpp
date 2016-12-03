
#include "stdio.h"
int main(int argc, char* argv[])
{   
	void sort(int *p);
	int nums[3];
	int i;
	for(i=0;i<3;i++)
		scanf("%d",nums+i);
	sort(nums);
	for(i=0;i<3;i++)
	    printf("%d ",*(nums+i));
	return 0;
}
void sort(int *p)
{   void change(int *p,int *p1);
	if(*p<*(p+1))  change(p,(p+1));
    if(*p<*(p+2))  change(p,(p+2));
	if(*(p+1)<*(p+2))  change((p+1),(p+2));
}
void change(int *p,int *p1)
{   int temp;
   temp=*p;
   *p=*p1;
   *p1=temp;
}
