#include "nlohmann/json.hpp"

#include "LoginDto.h"
#include "HttpClient.hpp"
#pragma once
class LoginController
{
public:
	LoginController();
	virtual ~LoginController();
	void setCredentials(const string& username, const string& password);
	string sendCredentials();
	const string& getUsername() const;
private:
	LoginDto* loginDto;
	HttpClient* client;
protected:

};

