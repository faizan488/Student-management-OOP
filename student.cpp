#include "student.h"

void student::login() {
    cout << "--- Student Portal ---" << endl;
}

void student::viewProfile() {
    cout << "Welcome to student portal" << endl;
}

void student::getDetails() {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your roll: ";
    cin >> roll;
    cout << "Enter your email: ";
    cin >> email;

    ofstream write("Student.txt", ios::app);
    write << "Student Details: " << name << " " << roll << " " << email << " ";
}

void student::gradeCalc() {
    ofstream write("Student.txt", ios::app);
    cout << "Enter your percentage: ";
    cin >> marks;

    if (marks > 90 && marks <= 100) {
        write << "Grade: A+\n";
        cout << "Your grade is A+\n";
    } else if (marks > 80) {
        write << "Grade: A\n";
        cout << "Your grade is A\n";
    } else if (marks > 70) {
        write << "Grade: B\n";
        cout << "Your grade is B\n";
    } else if (marks > 60) {
        write << "Grade: C\n";
        cout << "Your grade is C\n";
    } else if (marks > 50) {
        write << "Grade: D\n";
        cout << "Your grade is D\n";
    } else {
        write << "Fail\n";
        cout << "You are fail\n";
        exit(0);
    }

    write.close();
}

int student::applyCourses() {
    cout << "Enter the first course: ";
    cin >> course1;
    cout << "Enter the second course: ";
    cin >> course2;

    ifstream read("Admin.txt");
    if (!read) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    bool foundCourse1 = false, foundCourse2 = false;
    string line;
    while (getline(read, line)) {
        if (line.find(course1) != string::npos) foundCourse1 = true;
        if (line.find(course2) != string::npos) foundCourse2 = true;
    }
    read.close();

    if (foundCourse1 && foundCourse2) {
        cout << "You can apply for both courses: " << course1 << " and " << course2 << endl;
    } else {
        cout << "One or both courses not found." << endl;
    }

    return 0;
}
