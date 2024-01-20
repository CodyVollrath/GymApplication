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

bool LoginController::sendCredentials() {
	const string payload = this->loginDto->to_json();
	const string authTokenRawJson = this->client->post("http://localhost:5000/api/login", payload, { "Content-Type: application/json" });
	try {
		nlohmann::json authTokenJson = nlohmann::json::parse(authTokenRawJson);
		Singletons::setInstance(SignedUser(authTokenJson["username"], authTokenJson["firstName"], authTokenJson["lastName"], to_string(authTokenJson["employeeId"]), authTokenJson["authKey"]));
		return true;
	}
	catch (exception) {
		return false;
	}
	
}

const string& LoginController::getUsername() const {
	return this->loginDto->getUsername();
}