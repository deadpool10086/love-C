#include <iostream> 
#include <windows.h>  
using namespace std;
UINT cnt = 0;  
  
// ��ʱ���ص�����  
void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);  
// �̻߳ص�����  
DWORD CALLBACK ThreadProc(PVOID pvoid);    
  
// ������  
int main()  
{  
    DWORD dwThreadId;  
    // �����߳�  
    HANDLE hThread = CreateThread(NULL, 0, ThreadProc, 0, 0, &dwThreadId);   
    printf("hello, thread start!\n");  
    cin.get();      // �õ�������������˳�  
    return 0;  
}      
  
void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)  
{  
    cnt ++;  
    printf("thread count = %d\n", cnt);  
}  
  
DWORD CALLBACK ThreadProc(PVOID pvoid)  
{  
    MSG msg;  
   // PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);   
    SetTimer(NULL, 10, 100, TimeProc);  
    while(GetMessage(&msg, NULL, 0, 0))  
    {
        if(msg.message == WM_TIMER)  
        {  
        	TranslateMessage(&msg);    // ������Ϣ  
            DispatchMessage(&msg);     // �ַ���Ϣ  
        }  
    } 
	KillTimer(NULL, 10);  
    return 0;  
}  
