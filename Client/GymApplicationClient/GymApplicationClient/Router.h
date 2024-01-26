#pragma once
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/log.h>
#include "TransitionEvent.h"

// All Custom System Frames go here for routing
#include "LoginFrame.h"
#include "HomeFrame.h"
#include "UsersFrame.h"


/*
  Handles Transitions between frames
*/
class Router : public wxEvtHandler
{
public:
	Router(TransitionEnums startFrame = TransitionEnums::LOGIN_FRAME);
	virtual ~Router();
	virtual bool ProcessEvent(wxEvent& event) override;
	void TransitionFrame(TransitionEnums frameTransition);
private:
	wxFrame* currentFrame;
	void displaySelectedFrame(TransitionEnums frameTransition);
	void disposeCurrentFrame();

};

