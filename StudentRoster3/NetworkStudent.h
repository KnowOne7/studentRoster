#pragma once
#include "Degree.h"
#include "Student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	
	Degree getDegreeProgram();
	void setDegreeProgram(Degree program);
	void print();

	~NetworkStudent();
};