#include <Windows.h>
#include <iostream>

using namespace std;

//DWORD WINAPI Thread1(LPVOID lpParam)
//{
//	for(int i=0; i<10; i++)
//	{
//		cout << "张德生"  << endl; 
//	}
//}
//
//DWORD WINAPI Thread2(LPVOID lpParam)
//{
//	for(int i=0; i<10; i++)
//	{
//		cout << "你真帅" << endl;
//	}
// } 

DWORD WINAPI thread(LPVOID lpPatam)
{
	int * p = (int *)lpPatam;
	for(int i=0; i<10; i++)
	{
		cin >> p[i];
	}
//	cout << lpPatam << endl;
}
DWORD WINAPI output(LPVOID lpPatam)
{
	int * p = (int *)lpPatam;
	while(1) 
	{
		for(int i=0; i<10; i++)
		{
			cout << p[i] << endl;
			Sleep(1000);
		}
	}
}

int main(int argc,  char* argv[])
{
// unsigned long dwThreadID1 = 0;
// unsigned long dwThreadID2 = 1;
// HANDLE hThread1 = NULL;
// HANDLE hThread2 = NULL;
// hThread1 = CreateThread(NULL,0,Thread1,NULL,0,&dwThreadID1);
// hThread2 = CreateThread(NULL,0,Thread2,NULL,0,&dwThreadID2);
// WaitForSingleObject(hThread1,INFINITE);
// WaitForSingleObject(hThread2,INFINITE);
// CloseHandle(hThread1);
// CloseHandle(hThread2);
	int data[10];	
	unsigned long dwThreadId = 1;
	HANDLE hTHread = NULL;
	CreateThread(NULL, 0, output,data,0,&dwThreadId);
	hTHread	= CreateThread(NULL, 0, thread,data,0,&dwThreadId);
	WaitForSingleObject(hTHread,INFINITE);
//	output(data);
	CloseHandle(hTHread);
	Sleep(10000);
	
	return 0;
}
