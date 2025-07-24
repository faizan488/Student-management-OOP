#include "instructor.h"

void instructor::login() {
    cout << "What's your username?" << endl;
    cin >> username;
    cout << "What's the password?" << endl;
    cin >> password;
    if (username == "instructor" && password == "instructor123") {
        cout << "You are logged in successfully as an instructor." << endl;
    }
}

void instructor::viewProfile() {
    cout << "Welcome to instructor profile" << endl;
}

void instructor::assignGrade() {
    string studentName;
    int marks;
    cout << "Enter student name: ";
    cin >> studentName;
    cout << "Enter marks: ";
    cin >> marks;

    char grade;
    if (marks >= 90) grade = 'A';
    else if (marks >= 80) grade = 'B';
    else if (marks >= 70) grade = 'C';
    else if (marks >= 60) grade = 'D';
    else grade = 'F';

    ofstream write("Grades.txt", ios::app);
    if (write.is_open()) {
        write << "Student: " << studentName << ", Marks: " << marks << ", Grade: " << grade << endl;
        write.close();
        cout << "Grade " << grade << " assigned and saved for " << studentName << endl;
    } else {
        cerr << "Failed to open Grades.txt for writing.\n";
    }
}
