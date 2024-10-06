#include <wx/wx.h>
#include "../ui/MainFrame.h"

class MainApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit() {
    MainFrame* frame = new MainFrame("Proyecto wxWidgets con CMake");
    frame->Show(true);
    return true;
}

