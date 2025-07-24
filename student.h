#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "user.h"
using namespace std;

class student : public user {
    string name, email;
    int roll, marks;

public:
    string course1, course2;
    void login() override;
    void viewProfile() override;
    void getDetails();
    void gradeCalc();
    int applyCourses();
};
