#include <stdio.h>
#include <stdlib.h>
struct Zhan
{
	char fuhao[20];
	char *p;
} zhan1;
int main()
{
	int i=0;
	void push(char c);
	void out();
	int youxianji(char a,char b);           //我用这个来判定符号的优先级 
	zhan1.p=zhan1.fuhao;
	char c;
	do
	{
		scanf("%c",&c);
		if(c=='\n') break;                    
		if(c>=48&&c<=57||c=='['||c==']')        //加入了“[]”是为了表示多位数； 
		{
			printf("%c",c);                       //数字原样输出 
		}
		else
		{
			if(zhan1.p==zhan1.fuhao)         	//空栈直接入栈 
			push(c);
			else
			{
				if(c=='(')					//优先处理括号 
				push(c);
				else if(c==')')
				{
					do
					  out(c);
					while(*(zhan1.p-1)!='(');
					zhan1.p--;
				}
				else
				{
					if(youxianji(c,*(zhan1.p-1)))        //当当前符号优先于栈顶符号时入栈     使用p-1是因为我使p始终指向最高元素的下一个空间； 
					push(c);
					else
					{					
						while(!youxianji(c,*(zhan1.p-1))&&zhan1.p!=zhan1.fuhao)       //当当前符号低于栈顶符号时出栈直到当前符号高于栈顶符号或者栈空 
							out();
						push(c);					//然后入栈 
					}
				}
			}
		}	
	}	
	while(1);
	while(zhan1.p!=zhan1.fuhao)           //把栈内剩下的所有元素输出 
	out();
	printf("\n");
	return 0;
}
void push(char c)
{
	if(zhan1.p==zhan1.fuhao+20)
		{
			printf("full!");
			exit(0);
		}
	else
		*(zhan1.p++)=c;
}
void out()
{
	if(zhan1.p==zhan1.fuhao)
		{
			printf("empty");
			exit(0);
		}
	else
		printf("%c",*(--(zhan1.p)));
}
int youxianji(char a,char b)                     //同级或者高级算是“1”低级为“0”   
{
	if(a=='*'||a=='/')
		{
			if(b=='*'||b=='/')
			return 0;
			else
			return 1;
		}
	else if(b=='(')
		return 1;
	else
	return 0;	
}
