#include <iostream>
#include "admin.h"
#include "instructor.h"
#include "student.h"
using namespace std;

int main() {
    int choice;
    cout << "You want to login as: 1-Admin 2-Instructor 3-Student" << endl;
    cin >> choice;

    if (choice == 1) {
        int decide;
        admin a;
        a.login();
        while (true) {
            cout << "1- Add Courses\n2- Add Instructors\n3- Add Students\n4- Display Courses\n5- Assign courses\n6- Exit\n";
            cin >> decide;
            switch (decide) {
                case 1: a.addCourses(); break;
                case 2: a.addInstructor(); break;
                case 3: a.addStudent(); break;
                case 4: a.displayCourses(); break;
                case 5: a.assignCoursesToInstructor(); break;
                case 6: exit(0);
                default: cout << "Invalid input\n";
            }
        }
    } else if (choice == 2) {
        instructor b;
        b.login();
        b.viewProfile();
        b.assignGrade();
    } else if (choice == 3) {
        student c;
        c.login();
        c.getDetails();
        c.gradeCalc();
        c.applyCourses();
    }

    return 0;
}
