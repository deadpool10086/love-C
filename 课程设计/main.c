#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int servenum=0;

int main(int argc, char *argv[]) {

	int userNumber = 0,select = 0;
	User * userList[1000] = {0};
	
	if (diskRead(&userNumber,userList))  //��ȡ�ɹ�����0��ʧ�ܷ���1��
	{
		printf("�ļ���ȡ����"); 
	}
	
	while(1)
	{
		printf("*****************************************\n");
		printf("*          ����������Ҫ�����ҵ��       *\n");
		printf("*           ��1���½��û�:              *\n");
		printf("*           ��2����                 *\n");
		printf("*           ��3��ȡ�                 *\n");
		printf("*           ��4���˵���ѯ��             *\n");
		printf("*           ��0�������˳���             *\n");
		printf("*****************************************\n");
	    printf("        ������˵�ѡ�0~4��:");
		scanf("%d",&select);
		if(select == 1)
		{
			if(addUser(userNumber, userList))   //�����û��ɹ�����0��ʧ�ܷ���1�� 
			{
				printf("�����û�ʧ�ܡ�\n"); 
			}
			else
			{
				printf("�����û��ɹ��������û�idΪ:%d\n",userNumber);
				userNumber++;
			}
		}
		else if (select == 2)
		{
			if(moneyChange(1, userNumber, userList))  //���ɹ�����0��ʧ�ܷ���1��
			{
				printf("���ʧ�ܡ�\n"); 
			}
			else
			{
				printf("���ɹ���\n");
			}
		}
		else if (select == 3)
		{
			if(moneyChange(-1, userNumber, userList)) //���ɹ�����0��ʧ�ܷ���1��
			{
				printf("ȡ��ʧ�ܡ�\n"); 
			}
			else
			{
				printf("ȡ��ɹ���\n");
			}
		}
		else if (select == 4)   
		{
			if( search(userNumber, userList) ) //��ѯ�ɹ�����0��ʧ�ܷ���1��
			{
				printf("��ѯʧ��\n");
			}
			else
			{
				printf("��ѯ�ɹ�\n"); 
			}
		}
		else if (select == 0)
		{
			if(diskWrite ( userNumber, userList))  //�����˳��ɹ�����0��ʧ�ܷ���1�� 
			{
				printf("���̴���"); 
			}
			else
			{
				printf("���̳ɹ�!");
				break;
			}
		} 
		fflush(stdin);  //ˢ�����뻺������ 
	}

	return 0;
}
