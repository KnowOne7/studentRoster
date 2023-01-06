#include "Student.h"

std::string Student::getStudentId()
{
	return studentId;
}

std::string Student::getFirstName()
{
	return firstName;
}

std::string Student::getLastName()
{
	return lastName;
}

std::string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getNumDays()
{
	return numDays;
}

void Student::setStudentId(std::string studentId)
{
	this->studentId = studentId;
}

void Student::setFistName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(std::string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumDays(int numDays[])
{
	this->numDays = new int[3];
	for (size_t i = 0; i < 3; ++i)
		this->numDays[i] = numDays[i];
}

void Student::print()
{
	std::cout << "Student Id: " << studentId
		<< "\tName: " << firstName
		<< " " << lastName
		<< "\tAge: " << age
		<< "\tDays in Class { "
		<< numDays[0] << ", " << numDays[1] << ", " << numDays[2]
		<< " } \tDegree: ";

}

Student::Student()
{
	std::cout << "Student Constructor called for: " << studentId << std::endl;
}

Student::~Student() 
{
	std::cout << "Student Deconstructor called for: " << studentId << std::endl;
}

std::ostream& operator<<(std::ostream& os, Student& rhs)
{
	// TODO: insert return statement here
	os << rhs.studentId << "\t" << rhs.firstName << "\t" << rhs.lastName << "\t" << rhs.email << "\t" << rhs.age << "\t { " <<
		*(rhs.numDays) << " " << *(rhs.numDays + 1) << " " <<
		*(rhs.numDays + 2) << " }\t" << degreePrint[rhs.program];//  << std::endl;
	return os;
}
