#include <iostream>
#include <string.h>
#include <windows.h>
#include <wchar.h>
using namespace std;

const int a = 1 << 10;

void* CellFormat(int& x, int& y, int* addr){
    //return (BYTE*)addr + a * ((size_t)x + a * y);
}

void WriteToCell(void* data, int x, int y) {
    auto pCell = (BYTE*)data + (x * a + y) * a; //Removing the * a + 1 and the a * will change nothing. //This comment is old.
    //strcpy((char*)pCell, "some text data");
    const WCHAR text[] = L"Test";
    wcscpy_s((WCHAR*)pCell, wcslen(text)+1, text);


}
WCHAR* GetCell(void* data, int x, int y)
{
    auto p = (BYTE*)data + a * ((size_t)x + a * y);
    //WCHAR text[512];
    //wcscpy_s(text, (rsize_t)text, (PCWSTR)p);
    return (WCHAR*)p;

}


int main()
{

    SIZE_T size;

    //void* p = ::VirtualAlloc((LPVOID)0x5f5bc4, 128 << 10, MEM_COMMIT | MEM_RESERVE,PAGE_READWRITE);
    //if(!p) {
// some error occurred
    //}
    //cout<<&p<<endl;




    //cout<<a;
    //void* data = malloc(a*a*a);



    //strcpy((char*)data, "some text");
    //cout<<data<<endl;
    int ptr = 0x123;

    void* d = ::VirtualAlloc(nullptr, a*a*a, MEM_COMMIT | MEM_RESERVE,PAGE_READWRITE);

    cout<<&d<<endl;

    WriteToCell(d, 1, 1);
    wcout<<GetCell(d, 1, 1);

    //cout<<*e;
    return 0;
}
