#pragma once
#include <string>
using namespace std;

class user {
protected:
    string username;
    string password;

public:
    virtual void login() = 0;
    virtual void viewProfile() = 0;
};
