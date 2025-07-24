#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream read;
ofstream write;
class user
{
protected:
    string username;
    string password;

public:
    virtual void login() = 0;
    virtual void viewProfile() = 0;
};

class admin : public user
{
private:
protected:
    string students;
    string instructors;

public:
    string courses;
    void login() override
    {
        cout << "What's the username?" << endl;
        cin >> username;
        cout << "What's the password?" << endl;
        cin >> password;
        if (username == "admin" && password == "admin123")
        {
            cout << "Login successful" << endl;
        }
        else
        {
            cout << "Invalid credentials" << endl;
            exit(0);
        }
    }

    void viewProfile() override
    {
        cout << "Admin Panel" << endl;
    }

    vector<string> vec1; 
    
    void addCourses()
    {
        int size;
        cout << "Enter size of courses you want to add " << endl;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the course to add " << endl;
            cin >> courses;
            vec1.push_back(courses);
        }
        cout << "The available courses are : " << endl;
        ofstream write("Admin.txt", ios::app);
        write << "The available courses are ";
        for (int i = 0; i < vec1.size(); ++i)
        {
            cout << vec1[i] << " ";
            write << vec1[i] << " ";
        }
        write << endl;
        write.close();
        cout << endl;
    }

    void displayCourses()
    {
        cout << "Courses offered: ";
        for (string c : vec1)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    vector<string> vec2;
    void addInstructor()
    {
        int size;
        cout << "How many instructors you want to add " << endl;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the instructor to add " << endl;
            cin >> instructors;
            vec2.push_back(instructors);
        }
        ofstream write("Admin.txt", ios ::app);
        write << "The instructors are : ";
        for (int i = 0; i < vec2.size(); ++i)
        {
            cout << vec2[i] << " ";
            write << vec2[i] << " ";
        }
        write << endl;
        write.close();
        cout << endl;
    }

    vector<string> vec3;
    void addStudent()
    {
        int size;
        cout << "How many students you want to add " << endl;
        cin >> size;
        string students;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the students to add " << endl;
            cin >> students;
            vec3.push_back(students);
        }

        ofstream write("Admin.txt", ios ::app);
        write << "The new students are : ";
        for (int i = 0; i < vec3.size(); ++i)
        {
            cout << vec3[i] << " ";
            write << vec3[i] << " ";
        }
        write << endl;
        write.close();
        cout << endl;
    }

    void assignCoursesToInstructor()
    {
        string instructorName;
        string courseName;

        cout << "Enter instructor's name: ";
        cin >> instructorName;
        cout << "Enter course to assign: ";
        cin >> courseName;

        ofstream write("InstructorCourses.txt", ios::app);
        if (write.is_open())
        {
            write << "Instructor: " << instructorName << ", Course: " << courseName << endl;
            write.close();
            cout << "Assigned course '" << courseName << "' to instructor '" << instructorName << "' successfully.\n";
        }
        else
        {
            cerr << "Failed to open InstructorCourses.txt for writing.\n";
        }
    }
};

class instructor : public user
{
protected:
    int marks;

public:
    void login() override
    {
        cout << "What's your username?" << endl;
        cin >> username;
        cout << "What's the password?" << endl;
        cin >> password;
        if (username == "instructor" && password == "instructor123")
        {
            cout << "You are logged in successfully as an instructor. " << endl;
        }
    }

    void viewProfile() override
    {
        cout << "Welcome to instructor profile " << endl;
    }

    map<string, char> studentGrades;

    void assignGrade()
    {
        string studentName;
        int marks;
        cout << "Enter student name: ";
        cin >> studentName;
        cout << "Enter marks: ";
        cin >> marks;

        char grade;
        if (marks >= 90)
            grade = 'A';
        else if (marks >= 80)
            grade = 'B';
        else if (marks >= 70)
            grade = 'C';
        else if (marks >= 60)
            grade = 'D';
        else
            grade = 'F';

        // Save to file
        ofstream write("Grades.txt", ios::app);
        if (write.is_open())
        {
            write << "Student: " << studentName << ", Marks: " << marks << ", Grade: " << grade << endl;
            write.close();
            cout << "Grade " << grade << " assigned and saved for " << studentName << endl;
        }
        else
        {
            cerr << "Failed to open Grades.txt for writing.\n";
        }
    }
};

class student : public user
{
    string name;
    string email;
    int roll;
    int marks;

public:
    string course1;
    string course2;
    void login() override
    {
        cout << "--- Student Portal --- " << endl;
    }

    void viewProfile() override
    {
        cout << "Welcome to student portal" << endl;
    }
    void getDetails()
    {
        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter your roll: " << endl;
        cin >> roll;
        cout << "Enter your email: " << endl;
        cin >> email;
        ofstream write("Student.txt", ios ::app);
        write << "Student Details :" << name << " " << roll << " " << email << " " << marks << " " ;
    }

    void gradeCalc()
    {   
        ofstream write("Student.txt", ios ::app);
        cout << "Enter your percentage " << endl;
        cin >> marks;
        if (marks > 50 && marks <= 60)
        {
            write << "Grade : D" << endl;
            cout << "Your grade is D" << endl;
        }
        else if (marks > 60 && marks <= 70)
        {
            write<< "Grade : C" << endl;
            cout<< "Your grade is C" << endl;
        }
        else if (marks > 70 && marks <= 80)
        {
            write<< " Grade : B" << endl;
         cout<< "Your grade is B" << endl;}
        else if (marks > 80 && marks <= 90)
        {
            write<< "Grade : A" << endl;
         cout<< "Your grade is A" << endl;}
        else if (marks > 90 && marks <= 100)
        {
            write<< "Grade : A+" << endl;
        cout<< "Your grade is A+" << endl; }
        else
        {
            write<< "Fail" << endl;
            cout<< "You are fail"<< endl;exit(0);
            write.close();
        }
    }

int applyCourses() {
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
        if (line.find(course1) != string::npos) {
            foundCourse1 = true;
        }
        if (line.find(course2) != string::npos) {
            foundCourse2 = true;
        }
    }

    read.close();

    if (foundCourse1 && foundCourse2) {
        cout << "You can apply for both courses: " << course1 << " and " << course2 << endl;
    } else {
        cout << "One or both courses not found." << endl;
    }

    return 0;
}
};
int main()
{
    int choice;
    cout << "You want to login as : 1-Admin 2-Instructor 3-Student" << endl;
    cin >> choice;
    if (choice == 1)
    {
        int decide;
        admin a;
        a.login();
        while (true)
        {
            cout << "1- Add Courses\n2- Add Instructors\n3- Add Students\n4- Display Courses\n5- Assign courses\n6-Exit\n";
            cin >> decide;
            switch (decide)
            {
            case 1:
                a.addCourses();
                break;
            case 2:
                a.addInstructor();
                break;
            case 3:
                a.addStudent();
                break;
            case 4:
                a.displayCourses();
                break;
            case 5:
                a.assignCoursesToInstructor();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid input\n";
            }
        }
    }
    else if (choice == 2)
    {
        instructor b;
        b.login();
        b.viewProfile();
        b.assignGrade();
    }
    else if (choice == 3)
    {
        student c;
        c.login();
        c.getDetails(); 
        c.gradeCalc();
        c.applyCourses();
    }
    return 0;
}
