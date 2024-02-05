#include "Popup.h"

Popup::Popup(wxWindow* parent, const wxString& title, const vector<wxString>& fieldNames) : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE) {
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	
	for (const auto& field : fieldNames) {
		wxStaticText* label = new wxStaticText(this, wxID_ANY, field + wxT(":"));
		wxTextCtrl* textField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

		wxBoxSizer* fieldSizer = new wxBoxSizer(wxHORIZONTAL);
		fieldSizer->Add(label, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
		fieldSizer->Add(textField, 1, wxEXPAND | wxALL, 5);

		mainSizer->Add(fieldSizer);
	}


	// Add buttons
	wxStdDialogButtonSizer* buttonSizer = new wxStdDialogButtonSizer();

	buttonSizer->AddButton(new wxButton(this, wxID_OK));
	buttonSizer->AddButton(new wxButton(this, wxID_CANCEL));
	buttonSizer->Realize();

	mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxALL, 5);
	SetSizerAndFit(mainSizer);
}

Popup::~Popup()
{
}


