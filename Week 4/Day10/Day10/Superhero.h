#pragma once
#include <string>
class Superhero
{
public:
	Superhero(std::string name, std::string secret, int age) :
		name_(name), 
		secret_(secret),
		age_(age)
	{	}
private:
	std::string name_, secret_;
	int age_;
};

