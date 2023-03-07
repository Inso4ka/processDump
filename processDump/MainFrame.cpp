#include <wx/wx.h>
#include <wx/sizer.h>
#include "MainFrame.h"
#include "SelectDialog.h"
#include "process.hpp"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
    m_procSelectWindow = new SelectDialog("Test", this);

    m_selectedProcNameText = new wxStaticText(this, wxID_ANY, "Selected process:");
    m_selectedProcNameLine = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    m_selectProcButton     = new wxButton(this, wxID_ANY, "Select", wxDefaultPosition, wxSize(80, 25));

    wxBoxSizer* processSelectSizer = new wxBoxSizer(wxHORIZONTAL);
    processSelectSizer->Add(m_selectedProcNameText, 0, wxTOP, 4);
    processSelectSizer->Add(m_selectedProcNameLine, 1, wxTOP, 1);
    processSelectSizer->Add(m_selectProcButton, 0, wxLEFT, 8);
    processSelectSizer->Add(5, 0);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(processSelectSizer, 0, wxEXPAND | wxALL, 5);
    SetSizer(mainSizer);
    Centre();

    m_selectProcButton->Bind(wxEVT_BUTTON, &MainFrame::OnSelectButtonClicked, this);
}

void MainFrame::SetSelectedProcess(const Process& process)
{
    m_selectedProcess = process;
    m_selectedProcNameLine->Clear();
    m_selectedProcNameLine->AppendText(process.name);
}

void MainFrame::OnSelectButtonClicked(wxCommandEvent& event)
{
    m_procSelectWindow->Centre();
    m_procSelectWindow->ShowModal();
}

MainFrame::~MainFrame()
{
    DESTROY_WXWIDGET(m_procSelectWindow);
}