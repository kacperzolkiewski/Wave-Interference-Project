#include <wx/wx.h>
#include "GUIMyFrame.h"
#include <thread>

class MyApp : public wxApp {

public:
    virtual bool OnInit();
    virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxFrame* mainFrame = new GUIMyFrame(NULL);
    mainFrame->SetTitle("Projekt 09 - WAVE INTERFERENCE");
    mainFrame->Show(true);

    SetTopWindow(mainFrame);

    return true;
}