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
	int youxianji(char a,char b);           //����������ж����ŵ����ȼ� 
	zhan1.p=zhan1.fuhao;
	char c;
	do
	{
		scanf("%c",&c);
		if(c=='\n') break;                    
		if(c>=48&&c<=57||c=='['||c==']')        //�����ˡ�[]����Ϊ�˱�ʾ��λ���� 
		{
			printf("%c",c);                       //����ԭ����� 
		}
		else
		{
			if(zhan1.p==zhan1.fuhao)         	//��ջֱ����ջ 
			push(c);
			else
			{
				if(c=='(')					//���ȴ������� 
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
					if(youxianji(c,*(zhan1.p-1)))        //����ǰ����������ջ������ʱ��ջ     ʹ��p-1����Ϊ��ʹpʼ��ָ�����Ԫ�ص���һ���ռ䣻 
					push(c);
					else
					{					
						while(!youxianji(c,*(zhan1.p-1))&&zhan1.p!=zhan1.fuhao)       //����ǰ���ŵ���ջ������ʱ��ջֱ����ǰ���Ÿ���ջ�����Ż���ջ�� 
							out();
						push(c);					//Ȼ����ջ 
					}
				}
			}
		}	
	}	
	while(1);
	while(zhan1.p!=zhan1.fuhao)           //��ջ��ʣ�µ�����Ԫ����� 
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
int youxianji(char a,char b)                     //ͬ�����߸߼����ǡ�1���ͼ�Ϊ��0��   
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
