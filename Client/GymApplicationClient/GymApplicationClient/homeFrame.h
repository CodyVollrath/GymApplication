#pragma once
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <string>
using namespace std;

#include "Singletons.h"

// Custom Events
#include "TransitionEvent.h"

class HomeFrame : public wxFrame
{
private:
	void OnUserBtnClick(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

protected:
	wxMenuBar* menuBar;
	wxMenu* fileMenuBtn;
	wxMenu* viewMenuBtn;
	wxMenu* aboutMenuBtn;
	wxMenu* dataMenuBtn;
	wxPanel* mainPanel;
	wxButton* crateUserBtn;
	wxEvtHandler* transitionHandler;
public:

	HomeFrame(wxEvtHandler* transitionHandler, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~HomeFrame();

};

