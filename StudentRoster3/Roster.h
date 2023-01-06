#pragma once
#include <string>
#include "Student.h"



int numStudents = 5;
int index = -1;

//Data input as follows:
const std::string studentData[] =
{
	//"A5,Michael,Johnson,mjoh558@wgu.edu,39,5,10,25,SOFTWARE",
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Michael,Johnson,mjoh558@wgu.edu,39,5,10,25,SOFTWARE" //Modify Student Data
};

class Roster
{
public:	
	Roster();
	Roster(int capacity);

	Student** classRosterArray;

	void add(std::string row, int i);
	void printAll();
	void singlePrint(int i);
	void remove(std::string studentId);
	void printDaysInCourse(std::string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	void space();


	~Roster();


	

};




