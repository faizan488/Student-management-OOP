#include "admin.h"

void admin::login() {
    cout << "What's the username?" << endl;
    cin >> username;
    cout << "What's the password?" << endl;
    cin >> password;
    if (username == "admin" && password == "admin123") {
        cout << "Login successful" << endl;
    } else {
        cout << "Invalid credentials" << endl;
        exit(0);
    }
}

void admin::viewProfile() {
    cout << "Admin Panel" << endl;
}

void admin::addCourses() {
    int size;
    cout << "Enter size of courses you want to add: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter the course to add: ";
        cin >> courses;
        vec1.push_back(courses);
    }

    ofstream write("Admin.txt", ios::app);
    write << "The available courses are: ";
    for (string c : vec1) {
        cout << c << " ";
        write << c << " ";
    }
    write << endl;
    write.close();
    cout << endl;
}

void admin::displayCourses() {
    cout << "Courses offered: ";
    for (string c : vec1) {
        cout << c << " ";
    }
    cout << endl;
}

void admin::addInstructor() {
    int size;
    cout << "How many instructors you want to add: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter the instructor to add: ";
        cin >> instructors;
        vec2.push_back(instructors);
    }

    ofstream write("Admin.txt", ios::app);
    write << "The instructors are: ";
    for (string inst : vec2) {
        cout << inst << " ";
        write << inst << " ";
    }
    write << endl;
    write.close();
    cout << endl;
}

void admin::addStudent() {
    int size;
    cout << "How many students you want to add: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter the student to add: ";
        cin >> students;
        vec3.push_back(students);
    }

    ofstream write("Admin.txt", ios::app);
    write << "The new students are: ";
    for (string stu : vec3) {
        cout << stu << " ";
        write << stu << " ";
    }
    write << endl;
    write.close();
    cout << endl;
}

void admin::assignCoursesToInstructor() {
    string instructorName, courseName;
    cout << "Enter instructor's name: ";
    cin >> instructorName;
    cout << "Enter course to assign: ";
    cin >> courseName;

    ofstream write("InstructorCourses.txt", ios::app);
    if (write.is_open()) {
        write << "Instructor: " << instructorName << ", Course: " << courseName << endl;
        write.close();
        cout << "Assigned course '" << courseName << "' to instructor '" << instructorName << "' successfully.\n";
    } else {
        cerr << "Failed to open InstructorCourses.txt for writing.\n";
    }
}
