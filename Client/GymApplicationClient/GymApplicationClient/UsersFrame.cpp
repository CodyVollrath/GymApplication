#include "UsersFrame.h"

enum ids {
	CREATE_USER_BTN = 1
};

wxBEGIN_EVENT_TABLE(UsersFrame, wxFrame)
EVT_BUTTON(CREATE_USER_BTN, UsersFrame::OnCreateUserClick)
wxEND_EVENT_TABLE()

UsersFrame::UsersFrame(wxEvtHandler* evtHandeler, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->evtHandler = evtHandler;
	this->popup = new Popup(this, "Add User", {"First Name", "Last Name", "Birthday", "Email", "Address", "State", "City", "Zip"});
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);


	mainPanel->SetSizer(panelSizer);
	mainPanel->Layout();
	panelSizer->Fit(mainPanel);
	mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 5);

	// List View
	this->usersListView = new wxListView(this->mainPanel);
	
	const int FIELD_LENGTH = 11;
	const string fields[FIELD_LENGTH] = {
		"ID", "First Name", "Last Name",
		"Date of Birth", "Date of Last Payment", 
		"Phone Number", "Email", "Address", "State", "City", "Zip"
	};
	
	const int widths[FIELD_LENGTH] = {80, 150, 150,100, 100, 100, 150, 150, 80, 100, 100};
	for (int i = 0; i < FIELD_LENGTH; i++) {
		this->usersListView->AppendColumn(fields[i]);
		this->usersListView->SetColumnWidth(i, widths[i]);
	}
	panelSizer->Add(this->usersListView, 1, wxEXPAND | wxALL, 5);
	// end list view

	createUserButton = new wxButton(this, CREATE_USER_BTN, wxT("Create User"), wxDefaultPosition, wxDefaultSize, 0);
	mainSizer->Add(createUserButton, 0, wxALL, 5);
	

	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

void UsersFrame::OnCreateUserClick(wxCommandEvent& event)
{
	this->popup->ShowModal();
}

UsersFrame::~UsersFrame()
{
}
