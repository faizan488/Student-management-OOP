#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "user.h"
using namespace std;

class instructor : public user {
protected:
    int marks;

public:
    void login() override;
    void viewProfile() override;
    map<string, char> studentGrades;
    void assignGrade();
};
