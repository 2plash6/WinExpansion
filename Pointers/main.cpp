#include <iostream>
using namespace std;
int main()
{
    char ch2[20];
    char pointer = *ch2;
    for(int i=0;i<26;i++){
        ch2[i] = i+64;
        cout << &pointer + i<< endl;
    }
    for(int i=0;i<26;i++){
    }
    return 0;
}
