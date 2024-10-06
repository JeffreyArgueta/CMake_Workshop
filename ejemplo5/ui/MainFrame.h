#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    
private:
    void OnButtonClick(wxCommandEvent& event);
    void OnSecondButtonClick(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif // MAINFRAME_H
