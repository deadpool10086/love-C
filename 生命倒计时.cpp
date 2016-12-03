#include <iostream>
#include <windows.h> 
#include <time.h>


using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int star=0, end=0, day=0,a;
	unsigned seconds1=0,seconds2=0;
	seconds1=2682374400UL;
	for(int i=1970;i < 1997;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
		day+=366;
		else
		day+=365;
	}
	day=day+31+28+31+30+31+30+31+31+30+31+30+27;
	seconds2=(day<<7)*675;   // //second µÈÓÚseconds=day*24*60*60 
	a-=seconds2;
	star=end=time(0);
	while(1)
	{
		if(star!=end)
		{
			system("cls");
			a=time(NULL);
			a-=seconds2;
			cout << seconds1-a <<endl;
			cout << a <<endl;
			star=end;
		}
		Sleep(999);
		end=time(0);
	}
	
	return 0; 
}
