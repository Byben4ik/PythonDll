#pragma once

#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "windows.h"

extern "C" LIBRARY_API int WINAPI printHello(int i);
extern "C" LIBRARY_API WORD WINAPI printArgs(WORD function, WORD * handle, DWORD * lp, WORD * p, BYTE * buffer, WORD bufferSize, wchar_t* str);

