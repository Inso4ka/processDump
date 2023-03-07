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
    wxButton*     m_selectProcButton;
    SelectDialog* m_procSelectWindow{};
    void          OnSelectButtonClicked(wxCommandEvent& event);
    Process       m_selectedProcess{};

  public:
    MainFrame(const wxString& title = "My application");
    void SetSelectedProcess(const Process& process);
    virtual ~MainFrame();
};