#pragma once

#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

using processArray_t = std::vector<PROCESSENTRY32>;

struct Process
{
    std::string name{};
    DWORD       id{};
};

processArray_t GetAllProcesses();
DWORD          GetProcessIdByName(const wchar_t* procname);
bool           GetModuleBaseAddress(DWORD processId, const wchar_t* modName, uintptr_t* pModbase);
bool           GetProcessModuleInfo(DWORD processId, const wchar_t* modName, MODULEENTRY32* pModEntry);