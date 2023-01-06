#include "Roster.h"
#include "Student.h"
#include "SoftwareStudent.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "Degree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Roster::Roster()
{
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->classRosterArray = new Student * [capacity];
}


void Roster::add(string row, int i) {

	std::vector <std::string> token;

	for (size_t i = 0; i < 9; ++i) {
		std::string token_id = row.substr(0, row.find(","));
		token.push_back(token_id);
		row.erase(0, row.find(",") + 1);
	}
	// cout << i << endl;
	if (token.at(8) == "SECURITY") {
		classRosterArray[i] = new SecurityStudent();
	}
	if (token.at(8) == "NETWORK") {
		classRosterArray[i] = new NetworkStudent();
	}
	if (token.at(8) == "SOFTWARE") {
		classRosterArray[i] = new SoftwareStudent();
	}
	this->classRosterArray[i]->setStudentId(token.at(0));
	this->classRosterArray[i]->setFistName(token.at(1));
	this->classRosterArray[i]->setLastName(token.at(2));
	this->classRosterArray[i]->setEmail(token.at(3));
	this->classRosterArray[i]->setAge(stoi(token.at(4)));
	int array[3]{ stoi(token.at(5)), stoi(token.at(6)), stoi(token.at(7)) };
	this->classRosterArray[i]->setNumDays(array);
}

// Prints OPerator overload which isn't wwhat is required. Want to print Virtual. FIXED
void Roster::printAll()
{
	space();
	for (int i = 0; i < numStudents; ++i) {
		//cout << *classRosterArray[i] << endl; // print by operation overload
		this->classRosterArray[i]->print();
	}
}

void Roster::singlePrint(int i)
{
	space();
	cout << *classRosterArray[i] << endl; // print by operation overload
	(this->classRosterArray[i])->print(); // virtual print

}

void Roster::remove(string studentId)
{
	space();
	cout << "Remove Student: " << studentId << endl;
	bool exists = false;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			classRosterArray[i]->print(); // virtual print
			delete classRosterArray[i];
			exists = true;
			for (int j = i; j < numStudents; ++j) {
				classRosterArray[j] = classRosterArray[j+1];
			}
			--numStudents;
		}
	}
	if(!exists)
		cout << studentId << ": Student ID does not exist.\n";
}

void Roster::printDaysInCourse(string studentId)
{
	space();
	cout << "Print Days in Course: " << studentId << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			cout << studentId << ": ID found" << endl;
			classRosterArray[i]->print(); // virtual print
			int * d = classRosterArray[i]->getNumDays();
			double avgDays = (d[0] + d[1] + d[2])/ 3.0;
			cout << studentId << ": Average Days in Course\t " << avgDays << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	space();
	cout << "Print Invalid Emails" << endl;

	for (int i = 0; i < numStudents; ++i) {

		if ((classRosterArray[i]->getEmail().find(".") == (string::npos) ||
			(classRosterArray[i]->getEmail().find("@") == (string::npos)) ||
			(classRosterArray[i]->getEmail().find(" ") != (string::npos)))) 
		{
			cout << classRosterArray[i]->getEmail() << " is an invalid email. \n";
		}
			
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	space();
	cout << "Print Degree By Program: " << degreeProgram << ":" << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}		
	}
	cout << endl;
}

void Roster::space() {
	cout << "\n\n";
}

int main() {

	Roster *classRoster = new Roster(5);

	for (int i = 0; i < numStudents; ++i) {
		classRoster->add(studentData[i], i);
	}

	classRoster->printAll();
	
	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->printDaysInCourse("A5");

	classRoster->printInvalidEmails();

	classRoster->printByDegreeProgram(2);

	classRoster->singlePrint(3);


	cout << endl << endl;

	classRoster->~Roster();

	cout << "Memory Check" << endl;

return 0;

}



Roster::~Roster()
{
	cout << "Delete class Roster Array: " << numStudents << endl;
	for (int i = 0; i < numStudents; ++i) {
		delete this->classRosterArray[i];
	}
	//delete this;
}
