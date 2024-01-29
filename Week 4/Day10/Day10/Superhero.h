#pragma once
#include <string>
#include <fstream>
class Superhero
{
public:
	Superhero(std::string name, std::string secret, int age) :
		name_(name), 
		secret_(secret),
		age_(age)
	{	}

	//Superhero(std::string csvData, char delimiter)
	//{
	//	Deserialize(csvData, delimiter);//reads the name, secret, age for my object
	//}

	std::string Name() { return name_; }
	std::string Secret() { return secret_; }
	int Age() { return age_; }

	void Serialize(std::ostream& out, char delimiter);
	//void Deserialize(std::string csvData, char delimiter);
	static Superhero Deserialize(std::string csvData, char delimiter);

private:
	std::string name_, secret_;
	int age_;
};

