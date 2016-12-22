#include <iostream> 
#include <windows.h>  
using namespace std;
UINT cnt = 0;  
  
// 定时器回调函数  
void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);  
// 线程回调函数  
DWORD CALLBACK ThreadProc(PVOID pvoid);    
  
// 主函数  
int main()  
{  
    DWORD dwThreadId;  
    // 创建线程  
    HANDLE hThread = CreateThread(NULL, 0, ThreadProc, 0, 0, &dwThreadId);   
    printf("hello, thread start!\n");  
    cin.get();      // 得到键盘输入后再退出  
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
        	TranslateMessage(&msg);    // 翻译消息  
            DispatchMessage(&msg);     // 分发消息  
        }  
    } 
	KillTimer(NULL, 10);  
    return 0;  
}  
