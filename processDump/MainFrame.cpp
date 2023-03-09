#include <wx/wx.h>
#include <wx/sizer.h>
#include "MainFrame.h"
#include "SelectDialog.h"
#include "process.hpp"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
    m_procSelectWindow = new SelectDialog("Test", this);
    m_dirSelectWindow  = new wxDirDialog(NULL, "111", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    m_selectedProcNameText = new wxStaticText(this, wxID_ANY, "Selected process: ");
    m_selectedProcNameLine = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    m_selectProcButton     = new wxButton(this, wxID_ANY, "Select", wxDefaultPosition, wxSize(80, 25));

    m_selectedDirNameText  = new wxStaticText(this, wxID_ANY, "Selected directory: ");
    m_selectedDirNameLine  = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    m_selectDirButton      = new wxButton(this, wxID_ANY, "Select", wxDefaultPosition, wxSize(80, 25));

    m_dumpButton = new wxButton(this, wxID_ANY, "Dump", wxDefaultPosition, wxSize(80, 25));

    wxBoxSizer* processSelectSizer = new wxBoxSizer(wxHORIZONTAL);
    processSelectSizer->Add(m_selectedProcNameText, 0, wxTOP, 4);
    processSelectSizer->Add(m_selectedProcNameLine, 1, wxTOP, 1);
    processSelectSizer->Add(m_selectProcButton, 0, wxLEFT, 8);
    processSelectSizer->Add(5, 0);

    wxBoxSizer* DirSelectSizer = new wxBoxSizer(wxHORIZONTAL);
    DirSelectSizer->Add(m_selectedDirNameText, 0, wxTOP, 4);
    DirSelectSizer->Add(m_selectedDirNameLine, 1, wxTOP, 1);
    DirSelectSizer->Add(m_selectDirButton, 0, wxLEFT, 8);
    DirSelectSizer->Add(5, 0);


    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(processSelectSizer, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(DirSelectSizer, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(m_dumpButton, 0, wxEXPAND | wxALL, 5);
    SetSizer(mainSizer);
    Centre();

    m_selectProcButton->Bind(wxEVT_BUTTON, &MainFrame::OnSelectButtonClicked, this);
    m_selectDirButton->Bind(wxEVT_BUTTON, &MainFrame::OnDirSelectButtonClicked, this);
    m_dumpButton->Bind(wxEVT_BUTTON, &MainFrame::OnDumpButtonClicked, this);
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

void MainFrame::OnDirSelectButtonClicked(wxCommandEvent& event)
{
    m_dirSelectWindow->Centre();
    m_dirSelectWindow->ShowModal();
    m_selectedDirNameLine->Clear();
    m_selectedDirNameLine->AppendText(m_dirSelectWindow->GetPath() + "\\");
}

MainFrame::~MainFrame()
{
    DESTROY_WXWIDGET(m_procSelectWindow);
}