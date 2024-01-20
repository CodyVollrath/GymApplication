#include "User.h"

User::User(const string& username, const string& firstname, const string& lastname, const string& employeeId)
{
	this->username = username;
	this->firstname = firstname;
	this->lastname = lastname;
	this->employeeId = employeeId;
}

User::~User()
{
	// dtor
}

const string& User::getUsername() const
{
	return this->username;
}

const string& User::getFirstname() const
{
	return this->firstname;
}

const string& User::getLastname() const
{
	return this->lastname;
}

const string& User::getEmployeeId() const
{
	return this->employeeId;
}

void User::setFirstname(const string& firstname) {
	this->firstname = firstname;
}

void User::setLastname(const string& lastname) {
	this->lastname = lastname;
}

string User::to_json()
{
	nlohmann::json userJson;
	userJson["username"] = this->username;
	userJson["firstname"] = this->firstname;
	userJson["lastname"] = this->lastname;
	userJson["employeeId"] = this->employeeId;
	return userJson.dump();
}
