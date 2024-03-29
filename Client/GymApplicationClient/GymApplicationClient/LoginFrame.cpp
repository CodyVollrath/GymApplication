#include "LoginFrame.h"

enum ids {
	SUBMIT_BTN = 1
};


wxBEGIN_EVENT_TABLE(LoginFrame, wxFrame)
EVT_BUTTON(SUBMIT_BTN, LoginFrame::OnSubmitBtnClicked)
wxEND_EVENT_TABLE()

LoginFrame::LoginFrame(wxEvtHandler* transitionHandler, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->transitionHandler = transitionHandler;
	this->loginController = new LoginController();

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* usernameSizer;
	usernameSizer = new wxGridSizer(0, 2, 0, 0);

	usernameLbl = new wxStaticText(mainPanel, wxID_ANY, wxT("Username"), wxDefaultPosition, wxDefaultSize, 0);
	usernameLbl->Wrap(-1);
	usernameSizer->Add(usernameLbl, 0, wxALL, 5);

	usernameField = new wxTextCtrl(mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	usernameSizer->Add(usernameField, 0, wxALL, 5);


	panelSizer->Add(usernameSizer, 1, wxEXPAND, 5);

	wxGridSizer* passwordSizer;
	passwordSizer = new wxGridSizer(0, 2, 0, 0);

	passwordLbl = new wxStaticText(mainPanel, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0);
	passwordLbl->Wrap(-1);
	passwordSizer->Add(passwordLbl, 0, wxALL, 5);

	passwordField = new wxTextCtrl(mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
	passwordSizer->Add(passwordField, 0, wxALL, 5);


	panelSizer->Add(passwordSizer, 1, wxEXPAND, 5);

	this->errorLabel = new wxStaticText(mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	panelSizer->Add(errorLabel);
	
	submitButton = new wxButton(mainPanel, SUBMIT_BTN, wxT("Login"), wxDefaultPosition, wxDefaultSize, 0);
	panelSizer->Add(submitButton, 0, wxALL, 5);


	mainPanel->SetSizer(panelSizer);
	mainPanel->Layout();
	panelSizer->Fit(mainPanel);
	mainSizer->Add(mainPanel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);
}

LoginFrame::~LoginFrame()
{
	delete this->loginController;
	this->loginController = nullptr;
}

void LoginFrame::OnSubmitBtnClicked(wxCommandEvent& event) {
	wxString usernameTxt = this->usernameField->GetValue();
	wxString passwordTxt = this->passwordField->GetValue();
	this->loginController->setCredentials(usernameTxt.ToStdString(), passwordTxt.ToStdString());
	bool isLoggingSuccessful = this->loginController->sendCredentials();
	if (isLoggingSuccessful) {
		this->errorLabel->SetLabel("");
		TransitionEvent evt(TransitionEnums::HOME_FRAME, TRANSITION_FRAME_EVENT);
		wxPostEvent(this->transitionHandler, evt);
	}
	else {
		this->errorLabel->SetLabel("Credentials are Incorrect!");
	}
}
