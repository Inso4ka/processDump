#include "definitions.h"
#include "App.h"
#include "MainFrame.h"
wxIMPLEMENT_APP(Application);
//
//class Dumper
//{
//  public:
//    bool writeMiniDump(EXCEPTION_POINTERS* exceptionPointers, wchar_t* processName, wchar_t* dir)
//    {
//        // std::wcout << processName << std::endl;
//        // std::wcout << dir;
//        PROCESSENTRY32 entry;
//        entry.dwSize = sizeof(PROCESSENTRY32);
//
//        SYSTEMTIME stLocalTime;
//        GetLocalTime(&stLocalTime);
//
//        bool                           mDumpStatus = false;
//        MINIDUMP_TYPE                  dumpType    = MiniDumpWithFullMemory;
//        MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
//        exceptionInfo.ExceptionPointers = exceptionPointers;
//        exceptionInfo.ClientPointers    = NULL;
//
//        // wchar_t processName[] = L"notepad++.exe";
//        wchar_t file[MAX_PATH];
//        swprintf_s(file, L"%s%s-%04d%02d%02d-%02d%02d%02d.dmp", dir, processName, stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,
//                   stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond);
//        // std::wcout << file;
//
//        HANDLE hFile    = CreateFile(file, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
//
//        // if (Process32First(snapshot, &entry) == TRUE)
//        //{
//        //     while (Process32Next(snapshot, &entry) == TRUE)
//        //     {
//        //         if (wcscmp(entry.szExeFile, processName) == 0)
//        //         {
//        //             HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
//        //             exceptionInfo.ThreadId = GetThreadId(hProcess);
//
//        //            mDumpStatus = MiniDumpWriteDump(hProcess, entry.th32ProcessID, hFile, dumpType, &exceptionInfo, NULL, NULL);
//
//        //            CloseHandle(hProcess);
//        //        }
//        //    }
//        //}
//        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 4216);
//        mDumpStatus     = MiniDumpWriteDump(hProcess, 4216, hFile, dumpType, &exceptionInfo, NULL, NULL);
//
//        CloseHandle(snapshot);
//
//        return mDumpStatus;
//    };
//
//    void printAllProcesses()
//    {
//        PROCESSENTRY32 entry;
//        entry.dwSize = sizeof(PROCESSENTRY32);
//
//        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
//
//        if (Process32First(snapshot, &entry) == TRUE) {
//            while (Process32Next(snapshot, &entry) == TRUE) {
//                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
//                printf_s("%lu %ls\n", entry.th32ProcessID, entry.szExeFile);
//                // std::wcout << entry.th32ModuleID << " " << entry.szExeFile << std::endl;
//                CloseHandle(hProcess);
//            }
//        }
//
//        CloseHandle(snapshot);
//    }
//};
int main()
{

}