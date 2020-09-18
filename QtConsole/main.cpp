#include <iostream>
#include <vector>

#include <QtCore/QCoreApplication>

#include "functions.h"

using namespace std;

typedef WORD (WINAPI* MYPROC)(WORD, WORD*, DWORD*, WORD*, BYTE*, WORD);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HMODULE lib = nullptr;

    while (true)
    {
        lib = LoadLibrary(L"HelloWorldDll.dll");
        if (!lib)
        {
            cout << "Error load Dll 0x" << hex << GetLastError() << endl;
        }

        MYPROC func = nullptr;
        func = (MYPROC)GetProcAddress(lib, "_printArgs@24");
        if (!func)
        {
            cout << "Error Load function 0x" << hex << GetLastError() << endl;
        }

        WORD function = 100;
        WORD* handle = &function;
        DWORD l = 101;
        DWORD* lp = &l;
        WORD p = 102;
        WORD* pp = &p;

        vector<uint8_t> vec(20, 0xFF);

        BYTE* buffer = vec.data();
        WORD bufferSize = vec.size();

        auto result = func(function, handle, lp, pp, buffer, bufferSize);
        cout << "Result: " << result << endl;

        break;
    }
    if (lib)
        FreeLibrary(lib);
    return a.exec();
}
