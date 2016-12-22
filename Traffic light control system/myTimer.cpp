#include <iostream>
#include <windows.h>

using namespace std;

int aw = 0;

void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)
{
	aw ++;
	cout << aw << endl;
}

int main()
{
	DWORD dwThreadId;
	
	SetTimer(NULL, 10, 1000, TimeProc);
	cin.get();
	return 0;
}
