///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "HomeFrame.h"

///////////////////////////////////////////////////////////////////////////



wxDEFINE_EVENT(LOGIN_TRANSITION_EVENT, wxCommandEvent);
wxDECLARE_EVENT(LOGIN_TRANSITION_EVENT, wxCommandEvent);
wxBEGIN_EVENT_TABLE(HomeFrame, wxFrame)
EVT_COMMAND(wxID_ANY, LOGIN_TRANSITION_EVENT, HomeFrame::OnListenTransitionEvent)
wxEND_EVENT_TABLE()

HomeFrame::HomeFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	welcomelbl = new wxStaticText(mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	welcomelbl->Wrap(-1);
	panelSizer->Add(welcomelbl, 0, wxALL, 5);


	mainPanel->SetSizer(panelSizer);
	mainPanel->Layout();
	panelSizer->Fit(mainPanel);
	mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

void HomeFrame::OnListenTransitionEvent(wxCommandEvent& event) {
	HomeFrame* homeFrame = new HomeFrame(nullptr, wxID_ANY, wxT("Home Frame"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE);
	homeFrame->Show(true);
}


HomeFrame::~HomeFrame()
{

}
