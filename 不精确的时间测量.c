#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	time_t start,end;
	time(&start);
	void hanshu();
	sleep(10);
	time(&end);
	printf("%f",difftime(end,start));
	return 0;
}
