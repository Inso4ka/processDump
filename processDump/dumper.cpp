#pragma warning(disable : 4996)

#include <Windows.h>
#include <TlHelp32.h>
#include <minidumpapiset.h>
#include <string>

#include "dumper.hpp"

bool writeMiniDump(DWORD processID, const wchar_t* processName, const wchar_t* dir, EXCEPTION_POINTERS* exceptionPointers)
{
    SYSTEMTIME stLocalTime;
    GetLocalTime(&stLocalTime);

    bool                           mDumpStatus = false;
    MINIDUMP_TYPE                  dumpType    = MiniDumpWithFullMemory;
    MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
    exceptionInfo.ExceptionPointers = exceptionPointers;
    exceptionInfo.ClientPointers    = NULL;

    wchar_t file[MAX_PATH];
    swprintf_s(file, L"%s%s-%04d%02d%02d-%02d%02d%02d.dmp", dir, processName, stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,
               stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond);

    HANDLE hFile    = CreateFile(file, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_DUP_HANDLE | THREAD_ALL_ACCESS, FALSE, processID);
    
    mDumpStatus = MiniDumpWriteDump(hProcess, processID, hFile, dumpType, &exceptionInfo, NULL, NULL);

    CloseHandle(hProcess);
    CloseHandle(hFile);

    return mDumpStatus;
};

const wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t*     wc    = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}