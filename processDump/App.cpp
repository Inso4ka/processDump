#include "App.hpp"
#include "MainFrame.hpp"

bool Application::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}