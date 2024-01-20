#include "Singletons.h"

SignedUser* Singletons::instance = nullptr;

SignedUser* Singletons::getInstance() {
    return instance;
}

void Singletons::setInstance(const SignedUser& signedUser) {
    delete instance;
    instance = new SignedUser(signedUser.getUsername(), signedUser.getFirstname(), signedUser.getLastname(), signedUser.getEmployeeId(), signedUser.getAuthKey());
}

Singletons::Singletons() {}

Singletons::~Singletons() {
    delete instance;
}