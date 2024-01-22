#include "Student.h"
#include <iostream>

void Student::Study(float numberOfHours)
{
	std::cout << "Hello. My name is " << name_ << " and I am " << age_ <<
		" years old. I am currently studying for " << numberOfHours << " hours.";
	std::cout << "PLEASE do not bother me. (go away)\n";
}

Student::Student(int age, std::string name) 
{
	Age(age);
	Name(name);
}
