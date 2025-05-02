#include <iostream>
#include "MinHook.h"
#if defined _M_X64
#pragma comment(lib, "libMinHook.x64.lib")
#elif defined _M_IX86
#pragma comment(lib, "libMinHook.x86.lib")
#endif

using namespace std;
typedef int(WINAPI* MessageBoxW_t)(HWND, LPCWSTR, LPCWSTR, UINT);
MessageBoxW_t MSGPointer = nullptr;
//NewMSGPointer = nullptr;

int WINAPI MSGDetour(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    return MSGPointer(hWnd, L"Hooked!", lpCaption, uType);
}

int main()
{
    cout<<"Test";
    if (MH_Initialize() != MH_OK)
    {
        //return 1;
    }
    //if(MH_CreateHook(&MessageBoxW, &MSGDetour, reinterpret_cast<LPVOID*>(&MSGPointer)) != MH_OK))
    //{
    //    return 1;
    //}

    //MH_CreateHook()
    MessageBoxW(NULL, L"Hello", L"Title", NULL);
    return 0;
}
