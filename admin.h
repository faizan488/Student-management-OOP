#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "user.h"
using namespace std;

class admin : public user {
protected:
    string students;
    string instructors;

public:
    string courses;
    vector<string> vec1; // courses
    vector<string> vec2; // instructors
    vector<string> vec3; // students

    void login() override;
    void viewProfile() override;
    void addCourses();
    void displayCourses();
    void addInstructor();
    void addStudent();
    void assignCoursesToInstructor();
};
