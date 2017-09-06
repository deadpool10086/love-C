#include <stdio.h>

int main(int argc, char *argv[])
{
	char command[60];
	sprintf(command, "rm -f %s", argv[0]);
	printf("%s\n", command);
	system(command);
	system("clear");
	return 0;
}
