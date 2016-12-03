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
	
	printf("请输入用户姓名："); 
	scanf("%19s",user[sum]->userName);
	fflush(stdin);
	printf("请输入用户家庭住址："); 
	scanf("%199s",user[sum]->address);
	fflush(stdin);
	printf("请输入用户手机号："); 
	for(i = 0; i < 11; i++)
	{
		temp = getchar();
		if(temp < 48 || temp > 57)
		{
			free(user[sum]);
			printf("手机号错误！\t"); 
			return 1;
		}
		else
		user[sum]->phoneNum[i] = (char)temp;
	}
	fflush(stdin); //刷新输入缓存区； 
	user[sum]->phoneNum[i] = 0;
	
	unsigned char password[16] = {0}; 
	printf("请输入密码:");
	scanf("%16s", password);
	system("cls");	//清屏； 
	fflush(stdin);
	
	MD5_CTX md5;
	MD5Init(&md5);		//进行MD5取特征值。          		
	MD5Update(&md5,password,strlen((char *)password));
	MD5Final(&md5,user[sum]->password);
	
	printf("请再次输入密码:");
	scanf("%16s", password);
	system("cls");
	fflush(stdin);
	
	MD5Init(&md5);         		//进行MD5取特征值。 
	MD5Update(&md5,password,strlen((char *)password));
	MD5Final(&md5,password);
	
	for(i=0; i<16; i++)
	{
		if(password[i] != user[sum]->password[i])
		{
			free(user[sum]);
			printf("密码不一致！\t");
			return 1;
		}
	}
	
	user[sum] -> userRecord = NULL;
	
	user[sum] -> amount = 0;
	
	return 0;
}

int moneyChange(int flag, int sum, User ** user)  //flag为标志位1为存款，-1为取款. 
{
	MD5_CTX md5;
	Rec *temp; 
	char name[20];
	unsigned char password[16]; 
	int id,i;
	long long money=0;
	printf("请输入用户号：");
	scanf("%d",&id); 
	if(id >= sum)
	{
		printf("无此用户!\t");
		return 1;
	}
	else
	{
		printf("请输入密码：");
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
				printf("密码不一致！\t");
				return 1;
			}
		}
		
		if((temp = (Rec*)malloc(sizeof(Rec))) == NULL)
		{
			printf("内存空间不足。\t");
			return 1; 
		}
		
		fflush(stdin);
		printf("请输入经办人姓名:");
		scanf("%19s",temp->server);
		fflush(stdin);
		
		printf("请输入金额:");
		scanf("%lld",&money);
		fflush(stdin);
		
		if (money <= 0)
		{
			printf("金额有误。\t");
			return 1;
		}
		else if (flag == -1 && money > user[id]->amount)
		{
			printf("金额不足。\t");
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
	printf("请输入用户号：");
	scanf("%d",&id); 
	if(id >= sum)
	{
		printf("无此用户!\t");
		return 1;
	}
	else
	{
		printf("请输入密码：");
		scanf("%16s",password);
		system("cls");
		fflush(stdin);
		
		MD5Init(&md5);         		//进行MD5取特征值。 
		MD5Update(&md5,password,strlen((char *)password));
		MD5Final(&md5,password);
		
		for(i=0; i<16; i++)
		{
			if(password[i] != user[id]->password[i])
			{
				printf("密码不一致！\t");
				return 1;
			}
		}
		
		system("cls");
		printf("用户名：%s\n",user[id]->userName);
		printf("用户ID：%d\n",user[id]->userId);
		printf("用户住址：%s\n",user[id]->address);
		printf("手机号码：%s\n",user[id]->phoneNum);
		printf("用户余额：%lld\n\n",user[id]->amount);
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
					printf("交易单号：%d\n",temp->number);
					if(temp->deposit==1)
					{
						printf("交易类型：存款\n");
					}
					else
					{
						printf("交易类型：取款\n");
					}
					printf("经办人：%s\n",temp->server);
					printf("交易日期：%d ：%d  :  %d\n",temp->year,temp->month,temp->day);
					printf("交易金额：%lld\n\n",temp->sum);
					temp=temp->next;
				}
			}
			printf("输入任何字符继续，输入0退出:");
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
		printf("文件写入失败。\t");
		return 1;
	} 
	else
	{
		if (fwrite(&sum, 4, 1, filep) != 1)
		{
			printf("写入错误！\t");
			fclose(filep);
			return 1;
		}
		for(i=0; i<sum; i++)
		{
			if (fwrite(user[i], sizeof(User), 1, filep) != 1)
			{
				printf("写入错误！\t");
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
				printf("%s写入错误！\t",fName);
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
			printf("读出错误！\t");
			fclose(filep);
			return 1;
		}
		for(i=0; i<*sum; i++)
		{
			if((user[i] = (User*)malloc(sizeof(User))) == NULL)
			{
				printf("空间不足。"); 
				fclose(filep);
				return 1;
			} 
			 
			if (fread(user[i], sizeof(User), 1, filep) != 1)
			{
				printf("读出错误！\t");
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
			printf("空间不足。"); 
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
				printf("空间不足。"); 
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
