#include <cstdio>
#include <iostream>
#include "roster.h"

using namespace std;

int main() {

    //print header information

    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Programming language: C++" << endl;
    cout << "WGU Student ID: 011408803" << endl;
    cout << "Student: Tyler Guitroz" << endl << endl;

    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Tyler,Guitroz,tguitro@wgu.edu,28,20,15,18,9,SOFTWARE"

    };

    //create classRoster, add each student
    Roster* classRoster = new Roster();


    // Populate the roster from studentData
    for (const string& originalData : studentData) {
        string data = originalData;
        size_t pos = 0;
        string token;
        string parsedData[9];
        int index = 0;

        while ((pos = data.find(',')) != string::npos) {
            token = data.substr(0, pos);
            parsedData[index++] = token;
            data.erase(0, pos + 1);
        }
        parsedData[index] = data; // Last part (degree program)

        // Convert age and days in course to integers
        int age = stoi(parsedData[4]);
        int daysInCourse1 = stoi(parsedData[5]);
        int daysInCourse2 = stoi(parsedData[6]);
        int daysInCourse3 = stoi(parsedData[7]);

        // Convert degree program from string to enum
        DegreeProgram degreeProgram;
        if (parsedData[8] == "SECURITY") degreeProgram = SECURITY;
        else if (parsedData[8] == "NETWORK") degreeProgram = NETWORK;
        else degreeProgram = SOFTWARE;

        // Add student to roster
        classRoster->add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    // Print all students
    cout << "Displaying all students:" << endl;
    classRoster->printAll();
    cout << endl;

    // Print invalid emails
    cout << "Displaying invalid emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    // Print average days in course for each student
    cout << "Displaying average days in course for each student:" << endl;
    for (int i = 0; i <= 4; ++i) {
        classRoster->printAverageDaysInCourse(classRoster->findStudent(i)->getStudentID());
    }
    cout << endl;

    // Print students by degree program (SOFTWARE)
    cout << "Displaying students in degree program: SOFTWARE" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove student A3
    cout << "Removing student with ID A3:" << endl;
    classRoster->remove("A3");
    cout << endl;

    // Try to remove student A3 again
    cout << "Attempting to remove student with ID A3 again:" << endl;
    classRoster->remove("A3");
    cout << endl;

    // Clean up
    delete classRoster;
    return 0;
}
