#pragma once
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>
#include <wx/listctrl.h>

#include <string>

#include "Popup.h"

// Custom Events
#include "TransitionEvent.h"

using namespace std;

class UsersFrame : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();
protected:
	wxPanel* mainPanel;
	wxButton* createUserButton;
	wxEvtHandler* evtHandler;
	wxListView* usersListView;
	Popup* popup;

public:

	UsersFrame(wxEvtHandler* evtHandler, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Users"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	void OnCreateUserClick(wxCommandEvent& event);
	~UsersFrame();

};

