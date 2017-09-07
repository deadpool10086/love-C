#include <iostream>

int main()
{
	char buf[512] = {0};
	sscanf("123456","%s",buf);
	printf("%s\n",buf);
	sscanf("123456","%4s",buf);
	printf("%s\n",buf);
	sscanf("123456 ancdef","%[^n]",buf);
	printf("%s\n",buf);
	sscanf("123456abcdedfBCDEF","%[1-9a-z]",buf);
	printf("%s\n",buf);
	sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
	printf("%s\n", buf);
	sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
	printf("%s\n", buf);
	sscanf("hello, world",  "%*s%s",  buf);   
	printf("%s\n", buf); 
	return 0;
} 
