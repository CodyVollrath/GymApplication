#include "SignedUser.h"

SignedUser::SignedUser(const string& username, const string& firstname, const string& lastname, const string& employeeId, const string& authKey) : User(username, firstname, lastname, employeeId)
{
	this->authKey = authKey;
}

SignedUser::~SignedUser() {
	// dtor
}

const string& SignedUser::getAuthKey() const
{
	return this->authKey;
}

string SignedUser::to_json()
{
	nlohmann::json userJson;
	userJson["username"] = this->username;
	userJson["firstname"] = this->firstname;
	userJson["lastname"] = this->lastname;
	userJson["employeeId"] = this->employeeId;
	userJson["authKey"] = this->authKey;
	return userJson.dump();
}

