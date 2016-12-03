#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int servenum=0;

int main(int argc, char *argv[]) {

	int userNumber = 0,select = 0;
	User * userList[1000] = {0};
	
	if (diskRead(&userNumber,userList))  //读取成功返回0，失败返回1；
	{
		printf("文件读取错误。"); 
	}
	
	while(1)
	{
		printf("*****************************************\n");
		printf("*          请输入您的要办理的业务       *\n");
		printf("*           （1）新建用户:              *\n");
		printf("*           （2）存款：                 *\n");
		printf("*           （3）取款：                 *\n");
		printf("*           （4）账单查询：             *\n");
		printf("*           （0）存盘退出：             *\n");
		printf("*****************************************\n");
	    printf("        请输入菜单选项（0~4）:");
		scanf("%d",&select);
		if(select == 1)
		{
			if(addUser(userNumber, userList))   //新增用户成功返回0，失败返回1； 
			{
				printf("新增用户失败。\n"); 
			}
			else
			{
				printf("新增用户成功。新增用户id为:%d\n",userNumber);
				userNumber++;
			}
		}
		else if (select == 2)
		{
			if(moneyChange(1, userNumber, userList))  //存款成功返回0，失败返回1；
			{
				printf("存款失败。\n"); 
			}
			else
			{
				printf("存款成功。\n");
			}
		}
		else if (select == 3)
		{
			if(moneyChange(-1, userNumber, userList)) //存款成功返回0，失败返回1；
			{
				printf("取款失败。\n"); 
			}
			else
			{
				printf("取款成功。\n");
			}
		}
		else if (select == 4)   
		{
			if( search(userNumber, userList) ) //查询成功返回0，失败返回1；
			{
				printf("查询失败\n");
			}
			else
			{
				printf("查询成功\n"); 
			}
		}
		else if (select == 0)
		{
			if(diskWrite ( userNumber, userList))  //存盘退出成功返回0，失败返回1； 
			{
				printf("存盘错误！"); 
			}
			else
			{
				printf("存盘成功!");
				break;
			}
		} 
		fflush(stdin);  //刷新输入缓存区； 
	}

	return 0;
}
