#pragma once
#include "md5.h"
#include "UserData.h"

extern int servenum;
int addUser(int sum, User ** user);
int moneyChange(int flag, int sum, User ** user);
int search(int sum, User ** user);
int diskWrite(int sum, User ** user);
int diskRead(int *sum, User ** user);
