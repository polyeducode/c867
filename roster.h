#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <stdio.h>
#include <string>
using std::string;

//Deefine Roster Class
class Roster {
public:
	
	Roster();
	~Roster();

	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll() const;
	void printAverageDaysInCourse(string studentID) const;
	void printInvalidEmails() const;
	void printByDegreeProgram(DegreeProgram degreeProgram) const;
	Student *findStudent(int index) const;


private:
	// data member for incrementally adding student object in Roster::Add
	int lastIndex;
	Student** classRosterArray;
};

#endif /* roster_h */