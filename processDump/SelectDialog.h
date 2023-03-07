#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>

#include "MainFrame.h"

class SelectDialog : public wxDialog
{
  private:
    wxListCtrl* m_dataListCtrl{};
    wxButton*   m_procListButton{};
    wxButton*   m_windowListButton{};
    wxButton*   m_selectButton{};
    wxButton*   m_closeButton{};
    MainFrame*  m_mainFrame{};

    void OnCloseButtonClick(wxCommandEvent& event);
    void OnProcessButtonClick(wxCommandEvent& event);
    void OnSelectButtonClick(wxCommandEvent& event);

  public:
    SelectDialog(const wxString& title, MainFrame* mainFrame);

    friend class MainFrame;
};