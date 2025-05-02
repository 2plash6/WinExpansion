#include <iostream>
#include <windows.h>
#include <string>
#include "easyhook.h"

using namespace std;

//int WINAPI MessageBoxHook(HWND hWnd, LPCWSTR LpCText, LPCSTR LpCaption, UINT uType);

int WINAPI MessageBoxHook(HWND hWnd, LPCWSTR LpCText, LPCSTR LpCaption, UINT uType){
    return(hWnd, L"The hook worked!", L"Victory.", uType);
}



//MessageBoxHook a = NULL;

HMODULE hUser32 = LoadLibrary("user32");
FARPROC pMessageBoxW = GetProcAddress(hUser32, "MessageBoxW");

typedef int (WINAPI *MessageBoxW_t)(HWND, LPCWSTR, LPCWSTR, UINT);
MessageBoxW_t pMsgBox = (MessageBoxW_t)pMessageBoxW;

            // Now I can call MessageBoxW through the function pointer
MessageBoxW_t *pMsg = NULL;




int main()
{

    cout << GetProcAddress(hUser32, "MessageBoxW");
    HOOK_TRACE_INFO hHook = { NULL }; // keep track of our hook
    pMsgBox(NULL, L"Hello World!", L"Test", MB_OK);
    NTSTATUS result = LhInstallHook(
        pMsg,
        reinterpret_cast<LPVOID>(MessageBoxHook),
        NULL,
        &hHook);


    cout << "Hello world!" << endl;
    return 0;
}
