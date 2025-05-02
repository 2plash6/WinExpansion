#include <iostream>
#include <windows.h>
#include <thread>
#include <ctime>
#include <chrono>

using namespace std;

void a()
{
    HWND hwnda = FindWindow(NULL, "Command Prompt");

    MessageBox(hwnda, "Still using this computer?", "Windows 8.1", MB_YESNO);
}
void b()
{
    this_thread::sleep_for(chrono::milliseconds(5));
    HWND hwnd = FindWindow(NULL, "Windows 8.1");


        RECT Lpr;
        GetWindowRect(hwnd, &Lpr);
        int w = Lpr.right - Lpr.left;
        int h = Lpr.bottom - Lpr.top;
        MoveWindow(hwnd, 100, 100, w, h, SWP_NOSIZE);
        //SetWindowPos(hwnd, HWND_TOP, 100, 100, 200, 150, NULL);
        //this_thread::sleep_for(chrono::milliseconds(50));

}
int main()
{
    thread threada = thread(a);
    thread threadb = thread(b);

    threada.join();
    threadb.join();




    return 0;
}
