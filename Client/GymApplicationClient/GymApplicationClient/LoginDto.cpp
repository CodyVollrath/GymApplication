#include "LoginDto.h"

LoginDto::LoginDto(const string& username, const string& password) {
	this->username = username;
	this->password = password;
}

LoginDto::LoginDto() {

}

LoginDto::~LoginDto() {

}

const string& LoginDto::getUsername() const {
	return this->username;
}

const string& LoginDto::getPassword() const {
	return this->password;
}

void LoginDto::setUsername(const string& username) {
	this->username = username;
}

void LoginDto::setPassword(const string& password) {
	this->password = password;
}

string LoginDto::to_json() {
	nlohmann::json loginDto;
	loginDto["username"] = this->username;
	loginDto["password"] = this->password;
	return loginDto.dump();
}