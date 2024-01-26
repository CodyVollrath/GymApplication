#include "Router.h"

// Router inherits wxEvtHandler
Router::Router(TransitionEnums startFrame) {
	this->displaySelectedFrame(startFrame);
}


Router::~Router()
{
	this->disposeCurrentFrame();
}

bool Router::ProcessEvent(wxEvent& event)
{
	int eventType = event.GetEventType();
	if (eventType == wxEVT_NULL) {
		// Not a command event
		return wxEvtHandler::ProcessEvent(event);
	}
	
	TransitionEvent* transitionEvent = dynamic_cast<TransitionEvent*>(&event);
	if (transitionEvent) {
		TransitionEnums frameTransition =  static_cast<TransitionEvent&>(event).GetFrameTransition();
		this->TransitionFrame(frameTransition);
		return true;
	}
	return wxEvtHandler::ProcessEvent(event);
}

void Router::TransitionFrame(TransitionEnums frameTransition)
{
	this->disposeCurrentFrame();
	this->displaySelectedFrame(frameTransition);
}


void Router::displaySelectedFrame(TransitionEnums transitionFrame) {
	switch (transitionFrame) {
	case (TransitionEnums::LOGIN_FRAME):
		this->currentFrame = new LoginFrame(this, NULL, wxID_ANY, "Login", wxDefaultPosition, wxSize(300, 400));
		this->currentFrame->Show();
		break;
	case (TransitionEnums::HOME_FRAME):
		this->currentFrame = new HomeFrame(this, NULL, wxID_ANY, "Home", wxDefaultPosition, wxDefaultSize);
		this->currentFrame->Show();
		break;
	case (TransitionEnums::USERS_FRAME):
		this->currentFrame = new UsersFrame(this, NULL, wxID_ANY, "Users", wxDefaultPosition, wxDefaultSize);
		this->currentFrame->Show();
		break;
	default:
		throw runtime_error("INVALID FRAME ENUMURATION");
	}
}

void Router::disposeCurrentFrame()
{
	if (this->currentFrame) {
		this->currentFrame->Destroy();
		this->currentFrame = nullptr;
	}
}
