#include <nlohmann/json.hpp>
#include <string>
using namespace std;

#pragma once
class User
{
public:
	User(const string& username, const string& firstname, const string& lastname, const string& employeeId);
	virtual ~User();

	const string& getUsername() const;
	const string& getFirstname() const;
	const string& getLastname() const;
	const string& getEmployeeId() const;
	void setFirstname(const string& firstname);
	void setLastname(const string& lastname);
	virtual string to_json();

protected:
	string username;
	string firstname;
	string lastname;
	string employeeId;
};

