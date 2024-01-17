///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "homeFrame.h"

///////////////////////////////////////////////////////////////////////////

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

void HomeFrame::SetWelcomeLabel(const string& labelData) {
	this->welcomelbl->SetLabel(labelData);
}

HomeFrame::~HomeFrame()
{
}
