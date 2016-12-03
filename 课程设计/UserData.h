#pragma once

typedef struct UserRecord
{
	int  deposit;
	int number;
	int year, month, day;
	long long sum;
	char server[20];
	struct UserRecord * next;
}Rec;

typedef struct UserData
{
	int userId;
	char userName[20];
	unsigned char password[16];
	char address[200];
	char phoneNum[12];
	long long  amount;
	Rec * userRecord;
}User;


