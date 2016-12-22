#include <iostream>
#include <Windows.h>
#include "timer.h"

using namespace std;


void CALLBACK TimerProc(void* p)
{
    int i = *((int*)p);
    cout << i << endl;
}

int main()
{
    Timer timer;

    int i = 10;

    int *p = &i;

    timer.registerHandler(TimerProc, p);
    timer.setInterval(1000);
    timer.Start();

    ::Sleep(1000);

    for(; i > 0; i--)
    {
        cout << "hello" << endl;
        ::Sleep(1000);
    }

    timer.Cancel();
    system("pause");
}
