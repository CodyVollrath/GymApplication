#include <wx/wx.h>
#include "Router.h"
#include <iostream>
class App : public wxApp {
public:
    bool OnInit() {
        Router* router = new Router();
        return true;
    }
};

wxIMPLEMENT_APP(App);
