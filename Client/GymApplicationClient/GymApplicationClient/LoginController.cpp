#include "LoginController.h"

LoginController::LoginController() {
	this->loginDto = new LoginDto();
}

LoginController::~LoginController() {
	delete this->loginDto;
	this->loginDto = 0;
}

void LoginController::setCredentials(const string& username, const string& password) {
	this->loginDto->setUsername(username);
	this->loginDto->setPassword(password);
	
}

void LoginController::sendCredentials() {

}

const string& LoginController::getUsername() const {
	return this->loginDto->getUsername();
}