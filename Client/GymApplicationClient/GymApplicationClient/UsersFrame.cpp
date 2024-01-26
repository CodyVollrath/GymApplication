///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UsersFrame.h"

///////////////////////////////////////////////////////////////////////////

UsersFrame::UsersFrame(wxEvtHandler* evtHaandeler, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->evtHandler = evtHandler;

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	userGrid = new wxGrid(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	userGrid->CreateGrid(5, 5);
	userGrid->EnableEditing(true);
	userGrid->EnableGridLines(true);
	userGrid->EnableDragGridSize(false);
	userGrid->SetMargins(0, 0);

	// Columns
	userGrid->EnableDragColMove(false);
	userGrid->EnableDragColSize(true);
	userGrid->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	userGrid->EnableDragRowSize(true);
	userGrid->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	userGrid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
	userGrid->SetMinSize(wxSize(-1, 100));

	panelSizer->Add(userGrid, 0, wxALL, 5);


	mainPanel->SetSizer(panelSizer);
	mainPanel->Layout();
	panelSizer->Fit(mainPanel);
	mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 5);

	createUserButton = new wxButton(this, wxID_ANY, wxT("Create User"), wxDefaultPosition, wxDefaultSize, 0);
	mainSizer->Add(createUserButton, 0, wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

UsersFrame::~UsersFrame()
{
}
