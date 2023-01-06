#include <iostream>
#include "NetworkStudent.h"
#include "Student.h"
#include "Degree.h"


NetworkStudent::NetworkStudent() {
	setDegreeProgram(NETWORK);
	std::cout << "Network Constructor" << std::endl;
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORK;
}

void NetworkStudent::setDegreeProgram(Degree program) {
	this->program = NETWORK;
}

void NetworkStudent::print() {
	Student::print();
	std::cout << "Networking Student" << std::endl;
}

NetworkStudent::~NetworkStudent()
{
	std::cout << "Network Deconstructor" << std::endl;
}
