#include "student.h"
#include <iostream>
using std::string;
using namespace std;

// Default constructor
Student::Student() : age(0), degreeProgram(DegreeProgram::SECURITY) {
    daysInCourse[0] = daysInCourse[1] = daysInCourse[2] = 0;
}

// Parameterized constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degree) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

// Mutators (setters)
void Student::setStudentID(const string id) {
    studentID = id;
}

void Student::setFirstName(const string& first) {
    firstName = first;
}

void Student::setLastName(const string& last) {
    lastName = last;
}

void Student::setEmailAddress(const string& email) {
    emailAddress = email;
}

void Student::setAge(int newAge) {
    age = newAge;
}

void Student::setDaysInCourse(const int daysInCourse[]) {
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}

void Student::setDegreeProgram(const DegreeProgram& degree) {
    degreeProgram = degree;
}

// Accessors (getters)
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

// Print student data
void Student::print() const {
    cout << "Student ID: " << studentID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Email: " << emailAddress << endl;
    cout << "Age: " << age << endl;
    cout << "Days In Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << endl;
    cout << "Degree Program: " << degreeProgram << endl;
}

// Destructor
Student::~Student() {}
