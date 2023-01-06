#include <iostream>
#include "SoftwareStudent.h"
#include "Student.h"



SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(SOFTWARE);
	std::cout << "Software Constructor" << std::endl;
}

void SoftwareStudent::setDegreeProgram(Degree program) {
	this->program = SOFTWARE;
}

void SoftwareStudent::print() {
	Student::print();
	std::cout << "Software Student" << std::endl;

}
Degree SoftwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

SoftwareStudent::~SoftwareStudent() {
	std::cout << "Software Deconstructor" << std::endl;
}