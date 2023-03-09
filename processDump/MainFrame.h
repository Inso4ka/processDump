#pragma once

#include <wx/wx.h>

class MainFrame;

#include "process.hpp"
#include "SelectDialog.h"

#define DESTROY_WXWIDGET(widget)                                                                                                                     \
    if (widget) {                                                                                                                                    \
        widget->Destroy();                                                                                                                           \
    }

class MainFrame : public wxFrame
{
  private:
    wxTextCtrl*   m_selectedProcNameLine{};
    wxStaticText* m_selectedProcNameText;
    wxTextCtrl*   m_selectedDirNameLine{};
    wxStaticText* m_selectedDirNameText;
    wxButton*     m_selectProcButton;
    wxButton*     m_selectDirButton;
    wxButton*     m_dumpButton;
    SelectDialog* m_procSelectWindow{};
    wxDirDialog*  m_dirSelectWindow{};
    void          OnSelectButtonClicked(wxCommandEvent& event);
    void          OnDumpButtonClicked(wxCommandEvent& event);
    void          OnDirSelectButtonClicked(wxCommandEvent& event);
    Process       m_selectedProcess{};

  public:
    MainFrame(const wxString& title = "My application");
    void SetSelectedProcess(const Process& process);
    virtual ~MainFrame();
};