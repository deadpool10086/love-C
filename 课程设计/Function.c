#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Function.h"

int addUser(int sum, User ** user)
{
	int i,temp,flag;
	if ((user[sum] =(User *)malloc(sizeof(User))) == NULL)
	return 1;
	user[sum] -> userId = sum;
	
	printf("�������û�������"); 
	scanf("%19s",user[sum]->userName);
	fflush(stdin);
	printf("�������û���ͥסַ��"); 
	scanf("%199s",user[sum]->address);
	fflush(stdin);
	printf("�������û��ֻ��ţ�"); 
	for(i = 0; i < 11; i++)
	{
		temp = getchar();
		if(temp < 48 || temp > 57)
		{
			free(user[sum]);
			printf("�ֻ��Ŵ���\t"); 
			return 1;
		}
		else
		user[sum]->phoneNum[i] = (char)temp;
	}
	fflush(stdin); //ˢ�����뻺������ 
	user[sum]->phoneNum[i] = 0;
	
	unsigned char password[16] = {0}; 
	printf("����������:");
	scanf("%16s", password);
	system("cls");	//������ 
	fflush(stdin);
	
	MD5_CTX md5;
	MD5Init(&md5);		//����MD5ȡ����ֵ��          		
	MD5Update(&md5,password,strlen((char *)password));
	MD5Final(&md5,user[sum]->password);
	
	printf("���ٴ���������:");
	scanf("%16s", password);
	system("cls");
	fflush(stdin);
	
	MD5Init(&md5);         		//����MD5ȡ����ֵ�� 
	MD5Update(&md5,password,strlen((char *)password));
	MD5Final(&md5,password);
	
	for(i=0; i<16; i++)
	{
		if(password[i] != user[sum]->password[i])
		{
			free(user[sum]);
			printf("���벻һ�£�\t");
			return 1;
		}
	}
	
	user[sum] -> userRecord = NULL;
	
	user[sum] -> amount = 0;
	
	return 0;
}

int moneyChange(int flag, int sum, User ** user)  //flagΪ��־λ1Ϊ��-1Ϊȡ��. 
{
	MD5_CTX md5;
	Rec *temp; 
	char name[20];
	unsigned char password[16]; 
	int id,i;
	long long money=0;
	printf("�������û��ţ�");
	scanf("%d",&id); 
	if(id >= sum)
	{
		printf("�޴��û�!\t");
		return 1;
	}
	else
	{
		printf("���������룺");
		scanf("%16s",password);
		system("cls");
		fflush(stdin);
		
		MD5Init(&md5);         		
		MD5Update(&md5,password,strlen((char *)password));
		MD5Final(&md5,password);
		
		for(i=0; i<16; i++)
		{
			if(password[i] != user[id]->password[i])
			{
				printf("���벻һ�£�\t");
				return 1;
			}
		}
		
		if((temp = (Rec*)malloc(sizeof(Rec))) == NULL)
		{
			printf("�ڴ�ռ䲻�㡣\t");
			return 1; 
		}
		
		fflush(stdin);
		printf("�����뾭��������:");
		scanf("%19s",temp->server);
		fflush(stdin);
		
		printf("��������:");
		scanf("%lld",&money);
		fflush(stdin);
		
		if (money <= 0)
		{
			printf("�������\t");
			return 1;
		}
		else if (flag == -1 && money > user[id]->amount)
		{
			printf("���㡣\t");
			return 1;
		}
		
		time_t timep;  
	    struct tm *p;  
	    time(&timep);  
	    p = gmtime(&timep);
		
		user[id]->amount += flag*money;
		
		temp->deposit = flag;
		temp->sum = money;
		temp->number = servenum++;
		temp->year = p->tm_year + 1900;
		temp->month = p->tm_mon + 1;
		temp->day = p->tm_mday;
		temp->next =  user[id]->userRecord;
		user[id]->userRecord = temp;
	}
	return 0;	
}

int search(int sum, User ** user)
{
	MD5_CTX md5;
	int id,i;
	char button=1;
	Rec * temp;
	unsigned char password[16]; 
	printf("�������û��ţ�");
	scanf("%d",&id); 
	if(id >= sum)
	{
		printf("�޴��û�!\t");
		return 1;
	}
	else
	{
		printf("���������룺");
		scanf("%16s",password);
		system("cls");
		fflush(stdin);
		
		MD5Init(&md5);         		//����MD5ȡ����ֵ�� 
		MD5Update(&md5,password,strlen((char *)password));
		MD5Final(&md5,password);
		
		for(i=0; i<16; i++)
		{
			if(password[i] != user[id]->password[i])
			{
				printf("���벻һ�£�\t");
				return 1;
			}
		}
		
		system("cls");
		printf("�û�����%s\n",user[id]->userName);
		printf("�û�ID��%d\n",user[id]->userId);
		printf("�û�סַ��%s\n",user[id]->address);
		printf("�ֻ����룺%s\n",user[id]->phoneNum);
		printf("�û���%lld\n\n",user[id]->amount);
		printf("***********************************************\n");
		
		temp = user[id]->userRecord;
		while(button != '0')
		{
			for(i=0 ; i<5; i++)
			{
				if(temp == NULL)
				{
					printf("***********************************************\n");
					goto over; 
				}
				else 
				{
					printf("���׵��ţ�%d\n",temp->number);
					if(temp->deposit==1)
					{
						printf("�������ͣ����\n");
					}
					else
					{
						printf("�������ͣ�ȡ��\n");
					}
					printf("�����ˣ�%s\n",temp->server);
					printf("�������ڣ�%d ��%d  :  %d\n",temp->year,temp->month,temp->day);
					printf("���׽�%lld\n\n",temp->sum);
					temp=temp->next;
				}
			}
			printf("�����κ��ַ�����������0�˳�:");
			scanf("%c",&button);
			fflush(stdin);
		}
	}
over: 	return 0;
}

int diskWrite(int sum, User ** user)
{
	int i;
	char fName[20]={0};
	FILE *filep;
	Rec *temp, *temp1;
	if ((filep = fopen("clientInfo.data","wb")) == NULL)
	{
		printf("�ļ�д��ʧ�ܡ�\t");
		return 1;
	} 
	else
	{
		if (fwrite(&sum, 4, 1, filep) != 1)
		{
			printf("д�����\t");
			fclose(filep);
			return 1;
		}
		for(i=0; i<sum; i++)
		{
			if (fwrite(user[i], sizeof(User), 1, filep) != 1)
			{
				printf("д�����\t");
				fclose(filep);
				return 1;
			}
		}	
	}
	fclose(filep);
		
		
	for(i=0; i<sum; i++)
	{
		temp = user[i]->userRecord;
		sprintf(fName,"user_%d.data",i);
		filep = fopen(fName,"wb"); 
		
		while(temp)
		{
			if (fwrite(temp, sizeof(Rec), 1, filep) != 1)
			{
				printf("%sд�����\t",fName);
				break;
			}
			else
			{
				temp1 = temp;
				temp = temp->next;
				free(temp1);
			}
		}
		free(user[i]);
		fclose(filep);
	} 

	return 0;
}

int diskRead(int *sum, User ** user)
{
	FILE *filep;
	int i;
	Rec *temp;
	Rec **last;
	char fName[20] = {0};
	if((filep = fopen("clientInfo.data","rb")) == NULL)
	{
		return 1;
	}
	else
	{
		if (fread(sum, 4, 1, filep) != 1)
		{
			printf("��������\t");
			fclose(filep);
			return 1;
		}
		for(i=0; i<*sum; i++)
		{
			if((user[i] = (User*)malloc(sizeof(User))) == NULL)
			{
				printf("�ռ䲻�㡣"); 
				fclose(filep);
				return 1;
			} 
			 
			if (fread(user[i], sizeof(User), 1, filep) != 1)
			{
				printf("��������\t");
				fclose(filep);
				return 1;
			}
		}
	}
	fclose(filep);
	
	for(i=0; i<*sum; i++)
	{
		sprintf(fName,"user_%d.data",i);
		filep = fopen(fName,"rb"); 
		if((temp = (Rec*)malloc(sizeof(Rec))) == NULL)
		{
			printf("�ռ䲻�㡣"); 
			fclose(filep);
			return 1;
		}
		if (fread(temp, sizeof(Rec), 1, filep) != 1)
		{
			free(temp);
			continue;
		}
		
		user[i]->userRecord = temp;
		
		while(temp->next != 0)
		{
			last = &(temp->next);
			
			if((temp = (Rec*)malloc(sizeof(Rec))) == NULL)
			{
				printf("�ռ䲻�㡣"); 
				fclose(filep);
				return 1;
			}
			if (fread(temp, sizeof(Rec), 1, filep) != 1)
			{
				free(temp);
				break;
			}
			
			*last = temp;
		}
		fclose(filep);
	}
	return 0;
}
