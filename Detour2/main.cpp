#include <iostream>
#include "MinHook.h"


using namespace std;
typedef BOOL(WINAPI* pHookedMessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
pHookedMessageBoxA HookedMessageBoxPointer;

typedef int(WINAPI* MESSAGEBOXW)(HWND, LPCWSTR, LPCWSTR, UINT);
MESSAGEBOXW fpMessageBoxW = NULL;

typedef int (WINAPI *MessageBoxW_t)(HWND, LPCWSTR, LPCWSTR, UINT);
MessageBoxW_t RealMessageBoxW = nullptr;

int WINAPI HookedMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType) {
    // Print the caption (lpCaption) to the console
    wcout << L"Caption: " << lpCaption << endl;

    // Call the original MessageBoxW
    return RealMessageBoxW(hWnd, lpText, lpCaption, uType);
}

int WINAPI MyMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT){
    return HookedMessageBoxPointer(NULL, NULL, NULL, NULL);
}



void StartHook(){

    if (MH_STATUS() != MH_OK)
    {
        cout<<"Error";
    }
    cout<<"Hook began.";
    //MH_Initialize();
    return;
}

int main()
{
    //if (MH_Initialize() != MH_OK) {}
    //MH_STATUS WINAPI MH_Initialize();

    cout << "Hello world!" << endl;
    MessageBoxW(NULL, L"Hello", NULL, NULL);
    return 0;
}
