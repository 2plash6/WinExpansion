#include <iostream>
#include <windows.h>
#include <C:\Users\ReFus\Desktop\detours.h>

using namespace std;

bool Hook(void * toHook,  void * newFunc, int len){
    if (len < 5)
    {

    }
}



typedef BOOL(WINAPI* pHookedMessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

pHookedMessageBoxA HookedMessageBoxPointer;


//int WINAPI MyMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);

void i(){
    cout<<"i";
}


int main()
{
    cout << "Hello world!" << endl;
    //IntPtr
    LPVOID User32 = LoadLibrary("User32.dll");
    //DWORD MSGBoxAddr = LoadModule((LPCSTR)User32, (LPVOID)"MessageBoxA");

    //DWORD FuncToDetour = (MSGBoxAddr);
    pHookedMessageBoxA pMessageBoxA = MessageBoxA;
    //pHookedMessageBoxA MSGBoxAddr = (pHookedMessageBoxA)GetProcAddress((HMODULE)User32, MessageBoxA);

    DetourRestoreAfterWith();

    DetourUpdateThread(GetCurrentThread());
    MessageBoxA(NULL, "Original MessageBox!", "MessageBoxA", MB_OK);

    DetourAttach(&(PVOID&)*pMessageBoxA, HookedMessageBoxPointer);

    DetourTransactionBegin();
    MessageBoxA(NULL, "Really Original Messagebox!", "Original MessageBoxA", MB_OK);


    //WINAPI*

    return 0;

}

/*
typedef BOOL(WINAPI* FuncMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT);
FuncMessageBoxA pMessageBoxA = MessageBoxA;
BOOL WINAPI HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    std::cout << "Intercepted MessageBoxA called!" << std::endl;
    std::cout << "Text: " << lpText << std::endl;
    std::cout << "Caption: " << lpCaption << std::endl;
    BOOL result = pMessageBoxA(hWnd, "Hooked Function", lpCaption, uType);
    return result;
}
int main()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pMessageBoxA, HookedMessageBoxA);
    DetourTransactionCommit();
    // Hooked
    MessageBoxA(NULL, "Original MessageBox!", "Hooked MessageBoxA", MB_OK);
    getchar();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pMessageBoxA, HookedMessageBoxA);
    DetourTransactionCommit();
+    // Original
    MessageBoxA(NULL, "Really Original Messagebox!", "Original MessageBoxA", MB_OK);
    return 0;
}*/
