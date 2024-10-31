#include "roster.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor
Roster::Roster() {
    lastIndex = -1;
    classRosterArray = new Student*[5]; // 
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

// Add a new student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Remove a student by ID
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex--];
            found = true;
            cout << "Student with ID " << studentID << " removed." << endl;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: Student with ID " << studentID << " not found!" << endl;
    }
}

// Print all students in the roster
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

// Print the average days in course for a given student ID
void Roster::printAverageDaysInCourse(string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            cout << "Average days in course for student " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}

// Print invalid emails in the roster
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

// Print students by a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Find a student by index
Student* Roster::findStudent(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}

