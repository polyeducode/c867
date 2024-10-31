// student.h
#ifndef student_h
#define student_h
#include "degree.h"
#include <stdio.h>
#include <string>
using std::string;


class Student {
private:
    // Instance variables
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);

    // Mutators (setters)
    void setStudentID(const string id);
    void setFirstName(const string& first);
    void setLastName(const string& last);
    void setEmailAddress(const string& email);
    void setAge(int newAge);
    void setDaysInCourse(const int daysInCourse[]);
    void setDegreeProgram(const DegreeProgram& degree);

    // Accessors (getters)
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram() const;

    // print function
    void print() const;

    //Destrustor//
    ~Student();
};
               
#endif // student_h

