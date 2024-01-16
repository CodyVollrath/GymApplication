#include <wx/wx.h>
#include "LoginFrame.h"
#include <iostream>

class App : public wxApp {
public:
    bool OnInit() {

        LoginFrame* window = new LoginFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(300, 400));
        window->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);
