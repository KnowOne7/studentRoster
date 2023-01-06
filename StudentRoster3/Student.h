#pragma once
#include <string>
#include <iostream>
#include "Degree.h"


class Student
{
	friend std::ostream& operator<<(std::ostream& os, Student& rhs);

protected:
	std::string studentId {""};
	std::string firstName {""};
	std::string lastName {""};
	std::string email {""};
	int age {0};
	int* numDays;
	Degree program;

public:
	// Assessors
	std::string getStudentId();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	int getAge();
	int* getNumDays();

	virtual Degree getDegreeProgram() = 0;
	
	
	// Setters (mutators)
	void setStudentId(std::string studentId);
	void setFistName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmail(std::string email);
	void setAge(int age);
	void setNumDays(int numDays[]);

	virtual void setDegreeProgram(Degree program) = 0;

	
	virtual void print();

	// Constructors
	Student();

	virtual ~Student();


};

