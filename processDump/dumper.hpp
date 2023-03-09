#pragma once

bool writeMiniDump(DWORD processID, const wchar_t* processName, const wchar_t* dir, EXCEPTION_POINTERS* exceptionPointers);

const wchar_t* GetWC(const char* c);