#pragma once
#include <wx/event.h>
#include "GlobalEnums.hpp"
class TransitionEvent : public wxCommandEvent {
public:
	TransitionEvent(TransitionEnums frameTransition, wxEventType eventType, int id = wxID_ANY) : wxCommandEvent(eventType, id), frameTransition(frameTransition) {};

	TransitionEnums GetFrameTransition() const { return this->frameTransition; }

	wxEvent* Clone() const override {
		return new TransitionEvent(*this);
	}

private:
	TransitionEnums frameTransition;

};
wxDEFINE_EVENT(TRANSITION_FRAME_EVENT, TransitionEvent);
wxDECLARE_EVENT(TRANSITION_FRAME_EVENT, TransitionEvent);