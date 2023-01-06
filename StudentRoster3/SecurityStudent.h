#pragma once
#include "Degree.h"
#include "Student.h"

class SecurityStudent : public Student {
public:
	SecurityStudent();
	
	Degree getDegreeProgram();
	void setDegreeProgram(Degree program);
	void print();

	virtual ~SecurityStudent();

};