#include "HomeFrame.h"

enum ids {
	SUBMIT_BTN = 1
};


wxBEGIN_EVENT_TABLE(HomeFrame, wxFrame)
EVT_BUTTON(SUBMIT_BTN,HomeFrame::OnUserBtnClick)
wxEND_EVENT_TABLE()

HomeFrame::HomeFrame(wxEvtHandler* transitionHandler, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->transitionHandler = transitionHandler;
	menuBar = new wxMenuBar(0);
	fileMenuBtn = new wxMenu();
	wxMenuItem* SaveBtn;
	SaveBtn = new wxMenuItem(fileMenuBtn, wxID_ANY, wxString(wxT("Save")), wxEmptyString, wxITEM_NORMAL);
	fileMenuBtn->Append(SaveBtn);

	menuBar->Append(fileMenuBtn, wxT("File"));

	viewMenuBtn = new wxMenu();
	menuBar->Append(viewMenuBtn, wxT("View"));

	aboutMenuBtn = new wxMenu();
	menuBar->Append(aboutMenuBtn, wxT("About"));

	dataMenuBtn = new wxMenu();
	menuBar->Append(dataMenuBtn, wxT("Data"));

	this->SetMenuBar(menuBar);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* navBarSizer;
	navBarSizer = new wxGridSizer(2, 2, 0, 0);

	crateUserBtn = new wxButton(mainPanel, SUBMIT_BTN, wxT("Create User"), wxDefaultPosition, wxSize(70, 60), 0);
	navBarSizer->Add(crateUserBtn, 0, wxALL, 5);


	panelSizer->Add(navBarSizer, 1, wxEXPAND, 5);


	mainPanel->SetSizer(panelSizer);
	mainPanel->Layout();
	panelSizer->Fit(mainPanel);
	mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

void HomeFrame::OnUserBtnClick(wxCommandEvent& event)
{
	TransitionEvent evt(TransitionEnums::USERS_FRAME, TRANSITION_FRAME_EVENT);
	wxPostEvent(this->transitionHandler, evt);
}


HomeFrame::~HomeFrame()
{

}
