#pragma once
#include "Student.h"
#include "Degree.h"

class SoftwareStudent : public Student
{
public:
    SoftwareStudent();
    
    void setDegreeProgram(Degree program) override;

    void print() override;

    Degree getDegreeProgram() override;

    ~SoftwareStudent();
};

