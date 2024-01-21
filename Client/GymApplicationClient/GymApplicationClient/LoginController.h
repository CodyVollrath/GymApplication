#include "nlohmann/json.hpp"

#include "LoginDto.h"
#include "HttpClient.hpp"

#include "Singletons.h"

#pragma once
class LoginController
{
public:
	LoginController();
	virtual ~LoginController();
	void setCredentials(const string& username, const string& password);
	bool sendCredentials();
	const string& getUsername() const;
private:
	LoginDto* loginDto;
	HttpClient* client;
protected:

};

