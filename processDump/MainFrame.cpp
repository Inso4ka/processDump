#include <wx/wx.h>
#include <wx/sizer.h>
#include "MainFrame.hpp"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(1, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, 100, "Choose directory", wxPoint(50, 50), wxSize(100, 25));

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MainFrame::OnHello, this, 1);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this, 100);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("hello :)");
}