#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    time_t rawtime;
	struct tm *t;
	time(&rawtime);
	t=localtime(&rawtime);
	printf("当前时间是：%s",asctime(t));
    return 0;
}
