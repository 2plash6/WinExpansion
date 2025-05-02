#include <iostream>
#include <windows.h>

using namespace std;
    LRESULT CALLBACK msgDetour(int nCode, WPARAM wp, LPARAM lp){
        if (nCode == HCBT_CREATEWND){
           CREATESTRUCT *pcs = ((CBT_CREATEWND *)lp)->lpcs;
            if ((pcs->style & WS_DLGFRAME) || (pcs->style & WS_POPUP)) {

		}




        wchar_t className[256];
        wcscpy_s(className, L"MessageBoxW");
        if (wcscmp(className, L"MessageBoxW") == 0) {
            wcout << L"MessageBox created with caption: " << pcs->lpszName << endl;
        }

        return CallNextHookEx(0, nCode, wp, lp);
        }


    }
int main()
{


    //HMODULE hLib = LoadLibraryA("kernel32.dll");
    //PROC lb = GetProcAddress(hLib, "MessageBox");

    HHOOK hook = SetWindowsHookEx(WH_CBT, msgDetour, 0, GetCurrentThreadId());
    MessageBoxW(NULL, L"Still using this computer?", L"123", MB_SYSTEMMODAL | MB_OK | MB_ICONWARNING);
    SetWindowsHookEx(WH_CBT, msgDetour, 0, GetCurrentThreadId());




    //cout << "\nAddr: " << lb;
    UnhookWindowsHookEx(hook);

    return 0;
}
