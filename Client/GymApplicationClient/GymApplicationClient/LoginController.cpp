#include "LoginController.h"

LoginController::LoginController() {
	this->loginDto = new LoginDto();
	this->client = new HttpClient();
}

LoginController::~LoginController() {
	delete this->loginDto;
	delete this->client;
	this->loginDto = 0;
	this->client = 0;
}

void LoginController::setCredentials(const string& username, const string& password) {
	this->loginDto->setUsername(username);
	this->loginDto->setPassword(password);
	
}

string LoginController::sendCredentials() {
	const string payload = "{\"username\": \"" + this->loginDto->getUsername() + "\", \"password\": \"" + this->loginDto->getPassword() + "\"}";
	const string authTokenRawJson = this->client->post("http://localhost:5000/api/login", payload, { "Content-Type: application/json" });
	nlohmann::json authTokenJson = nlohmann::json::parse(authTokenRawJson);
	const string token = authTokenJson["authKey"];
	return token;
}

const string& LoginController::getUsername() const {
	return this->loginDto->getUsername();
}