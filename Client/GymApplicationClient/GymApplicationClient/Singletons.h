#pragma once

#include "SignedUser.h"

class Singletons {
public:
    static SignedUser* getInstance();  // Renamed to follow naming conventions
    static void setInstance(const SignedUser& signedUser);

private:
    static SignedUser* instance;

    Singletons();
    ~Singletons();

    // Disable copy constructor and assignment operator to enforce singleton
    Singletons(const Singletons&) = delete;
    Singletons& operator=(const Singletons&) = delete;
};