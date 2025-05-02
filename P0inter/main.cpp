#include <iostream>

using namespace std;

int main()
{
    int a = 4;
    int *e;
    e=&a;
    *e=10;

    int arr[26];
    int *er = arr - 1;

    cout<<*e<<endl<<e;
    for(int i=0;i<26;i++){
        arr[i] = i;

    }
    for(int i=0;i<26;i++){
        cout<<*er<<endl;
        er++;
    }

    return 0;
}
