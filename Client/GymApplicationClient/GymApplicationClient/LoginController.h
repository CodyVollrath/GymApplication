#include "LoginDto.h"
#pragma once
class LoginController
{
public:
	LoginController();
	virtual ~LoginController();
	void setCredentials(const string& username, const string& password);
	void sendCredentials();
	const string& getUsername() const;
private:
	LoginDto* loginDto;

protected:

};

