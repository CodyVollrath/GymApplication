///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>
#include <wx/frame.h>

// Our Headers
#include "LoginController.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class LoginFrame
///////////////////////////////////////////////////////////////////////////////
class LoginFrame : public wxFrame
{
private:
	LoginController* loginController;
	void OnSubmitBtnClicked(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
protected:
	wxPanel* mainPanel;
	wxStaticText* usernameLbl;
	wxTextCtrl* usernameField;
	wxStaticText* passwordLbl;
	wxTextCtrl* passwordField;
	wxButton* submitButton;

public:

	LoginFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~LoginFrame();

};

