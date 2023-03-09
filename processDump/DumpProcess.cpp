#include <wx/wx.h>
#include <wx/listctrl.h>
#include "MainFrame.h"
#include "dumper.hpp"
#include "process.hpp"

void MainFrame::OnDumpButtonClicked(wxCommandEvent& event)
{
    const wchar_t* pName = GetWC(m_selectedProcess.name.c_str());

    char dirStr[1024];
    strncpy(dirStr, (const char*)(m_dirSelectWindow->GetPath() + "\\").mb_str(wxConvUTF8), 1023);
    const wchar_t* dDir = GetWC(dirStr);
    writeMiniDump(m_selectedProcess.id, pName, dDir, nullptr);
}