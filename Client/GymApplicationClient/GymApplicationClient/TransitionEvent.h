#pragma once
#include <wx/event.h>
class TransitionEvent : public wxCommandEvent {
public:
	TransitionEvent(wxEventType eventType, int id = wxID_ANY) : wxCommandEvent(eventType, id) {};

	wxEvent* Clone() const override {
		return new TransitionEvent(*this);
	}

};