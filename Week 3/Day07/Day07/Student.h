#pragma once
#include <string>
class Student
{
public:
	void Study(float numberOfHours);

	//write getters/setters for name and age
	int Age() { return age_; }
	void Age(int age) {
		if (age >= 0 && age <= 120)
			age_ = age;
	}

	std::string Name() { return name_; }
	void Name(std::string name) {
		if (name.size() > 0)
			name_ = name;
	}

	//create a constructor to inialize the name and age

private:
	int age_;
	std::string name_;
};

