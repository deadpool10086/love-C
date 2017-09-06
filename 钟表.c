#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	time_t Time1,Time2;
	struct tm *tp;
	time(&Time1);
	tp=localtime(&Time1);
	printf("%s",asctime(tp));
	while(1)
	{
		time(&Time2);
		if(Time1!=Time2)
		{
			system("cls");
			tp=localtime(&Time2);
			printf("%s",asctime(tp));
			Time1=Time2;
		}
	}
	return 0;
}
