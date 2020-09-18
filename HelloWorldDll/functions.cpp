#include "functions.h"

#include <iostream>
#include <iomanip>

using namespace std;

int WINAPI printHello(int i)
{
    cout << "Hello World!" << endl;
    return i;
}

WORD WINAPI printArgs(WORD function, WORD* handle, DWORD* lp, WORD* p, BYTE* buffer, WORD bufferSize, wchar_t* str)
{
    cout << "function: " << function << endl;
    cout << "handle: " << handle << endl;
    cout << "lp: " << *lp << endl;
    cout << "p: " << *p << endl;

    cout << "buffer:" << endl;
    cout << hex;
    for (int i = 0; i < bufferSize; ++i)
    {
        cout << hex << setfill('0') << setw(2) << (int)buffer[i] << " ";
    }
    cout << dec;
    cout << endl;

    cout << "string:" << endl;
    wcout << str << endl;

    cout << dec;
    cout << endl;

    return wcslen(str);
}