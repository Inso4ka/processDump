#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

#include "process.hpp"

processArray_t GetAllProcesses()
{
    processArray_t result{};

    PROCESSENTRY32 procEntry{};
    procEntry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (hSnap != INVALID_HANDLE_VALUE) {
        if (Process32First(hSnap, &procEntry)) {
            do {
                if (procEntry.th32ProcessID)
                    result.push_back(procEntry);
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    CloseHandle(hSnap);
    return result;
}

DWORD GetProcessIdByName(const wchar_t* procname)
{
    DWORD processId = 0;
    auto  processes = GetAllProcesses();
    for (const auto& procEntry : processes) {
        if (!_wcsicmp(procEntry.szExeFile, procname)) {
            processId = procEntry.th32ProcessID;
            break;
        }
    }
    return processId;
}

bool GetProcessModuleInfo(DWORD processId, const wchar_t* modName, MODULEENTRY32* pModEntry)
{
    bool   found = false;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);
    if (hSnap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 modEntry{};
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry)) {
            do {
                if (!_wcsicmp(modEntry.szModule, modName)) {
                    *pModEntry = modEntry;
                    found      = true;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return found;
}

bool GetModuleBaseAddress(DWORD processId, const wchar_t* modName, uintptr_t* pModBase)
{
    MODULEENTRY32 modEntry{};
    modEntry.dwSize = sizeof(modEntry);
    bool bSuccess   = GetProcessModuleInfo(processId, modName, &modEntry);
    if (bSuccess) {
        *pModBase = reinterpret_cast<uintptr_t>(modEntry.modBaseAddr);
    }
    return bSuccess;
}