#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Date
{
	int yera,month,day;
} now;
int main(int argc, char *argv[]) {
	int n;
	printf("please input the date.\n");
	scanf("%d%d%d",&now.yera,&now.month,&now.day);
	n=now.month;
	switch(n)
	{
		case 1:n=now.day;break;
		case 2:n=now.day+31;break;
		case 3:n=now.day+59;break;
		case 4:n=now.day+90;break;
		case 5:n=now.day+120;break;
		case 6:n=now.day+151;break;
		case 7:n=now.day+181;break;
		case 8:n=now.day+212;break;
		case 9:n=now.day+243;break;
		case 10:n=now.day+273;break;
		case 11:n=now.day+304;break;
		case 12:n=now.day+334;break;
	}
	if(now.month>2&&(now.yera&4==0&&now.yera%100!=0||now.yera%400==0))
	n=n+1;
	printf("%d\n",n);
}
