#include <wx/wx.h>
#include <wx/listctrl.h>
#include "MainFrame.h"
#include "SelectDialog.h"
#include "process.hpp"

void SelectDialog::OnCloseButtonClick(wxCommandEvent& event)
{
    Close();
}

void SelectDialog::OnProcessButtonClick(wxCommandEvent& event)
{
    m_procListButton->Disable();
    auto processes = GetAllProcesses();
    m_dataListCtrl->DeleteAllItems();
    for (const auto& process : processes) {
        auto insertedIndex = m_dataListCtrl->InsertItem(0, wxString(process.szExeFile), 0);
        m_dataListCtrl->SetItem(insertedIndex, 1, wxString::Format("%i", process.th32ProcessID));
    }
    m_procListButton->Enable();
}

void SelectDialog::OnSelectButtonClick(wxCommandEvent& event)
{
    auto selectedIndex = m_dataListCtrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if (selectedIndex == -1)
        return;
    Process process{};
    process.name = m_dataListCtrl->GetItemText(selectedIndex);
    m_dataListCtrl->GetItemText(selectedIndex, 1).ToULong(&process.id);
    m_mainFrame->SetSelectedProcess(process);
    Close();
}

SelectDialog::SelectDialog(const wxString& title, MainFrame* mainFrame)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(350, 400)), m_mainFrame{mainFrame}
{
    m_dataListCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    m_dataListCtrl->InsertColumn(0, wxString("Name"));
    m_dataListCtrl->InsertColumn(1, wxString("ID"));

    m_procListButton   = new wxButton(this, wxID_ANY, "Process List");
    m_windowListButton = new wxButton(this, wxID_ANY, "Window List");
    m_selectButton     = new wxButton(this, wxID_ANY, "Select");
    m_closeButton      = new wxButton(this, wxID_ANY, "Close");

    wxBoxSizer* mainList = new wxBoxSizer(wxVERTICAL);
    mainList->Add(m_dataListCtrl, 1, wxEXPAND | wxLEFT | wxRIGHT, 24);

    wxGridSizer* mainButtons = new wxGridSizer(2, 2, 5, 15);
    mainButtons->Add(m_procListButton, 0, wxEXPAND);
    mainButtons->Add(m_windowListButton, 0, wxEXPAND);
    mainButtons->Add(m_selectButton, 0, wxEXPAND);
    mainButtons->Add(m_closeButton, 0, wxEXPAND);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(mainList, 1, wxEXPAND | wxTOP | wxBOTTOM, 10);
    mainSizer->Add(mainButtons, 0, wxALIGN_CENTER | wxBOTTOM, 8);

    m_closeButton->Bind(wxEVT_BUTTON, &SelectDialog::OnCloseButtonClick, this);
    m_procListButton->Bind(wxEVT_BUTTON, &SelectDialog::OnProcessButtonClick, this);
    m_selectButton->Bind(wxEVT_BUTTON, &SelectDialog::OnSelectButtonClick, this);

    SetSizer(mainSizer);
    Centre();
}