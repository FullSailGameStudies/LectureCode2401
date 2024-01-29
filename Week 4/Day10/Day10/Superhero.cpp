#include "Superhero.h"
#include <sstream>

void Superhero::Serialize(std::ostream& out, char delimiter)
{
	//write the hero data to the stream
	out << name_ << delimiter << secret_ << delimiter << age_ << "\n";
}

Superhero Superhero::Deserialize(std::string csvData, char delimiter)
{
    std::stringstream detailsStream(csvData);
    std::string name, secret, ageString;
    int age;
    std::getline(detailsStream, name, delimiter);
    std::getline(detailsStream, secret, delimiter);
    std::getline(detailsStream, ageString, delimiter);
    age = std::stoi(ageString);

    Superhero hero(name, secret, age);

	return hero;
}
