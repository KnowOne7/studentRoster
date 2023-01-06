#include<iostream>
#include "SecurityStudent.h"
#include "Student.h"


SecurityStudent::SecurityStudent() {
	setDegreeProgram(SECURITY);
	std::cout << "Security Constructor" << std::endl;
}

void SecurityStudent::setDegreeProgram(Degree program) {
	this->program = SECURITY;
}

void SecurityStudent::print() {
	Student::print();
	std::cout << "Security Student" << std::endl;
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;
}

SecurityStudent::~SecurityStudent() {
	std::cout << "Security Deconstructor" << std::endl;
}


