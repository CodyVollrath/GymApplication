#include "User.h"

#pragma once
class SignedUser : public User
{
public:
	SignedUser(const string& username, const string& firstname, const string& lastname, const string& employeeId, const string& authKey);
	virtual ~SignedUser();
	const string& getAuthKey() const;
	string to_json() override;
private:
	string authKey;
};

