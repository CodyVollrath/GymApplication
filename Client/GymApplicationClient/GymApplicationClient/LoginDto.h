#include <string>
#pragma once

using namespace std;

class LoginDto
{
public:
	LoginDto(const string& username, const string& password);
	LoginDto();
	virtual ~LoginDto();

	const string& getUsername() const;
	const string& getPassword() const;

	void setUsername(const string& username);
	void setPassword(const string& password);
private:
	string username;
	string password;

protected:
};
