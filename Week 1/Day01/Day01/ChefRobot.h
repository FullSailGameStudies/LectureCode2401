#pragma once
#include <string>
//using namespace std;//considered to be BAD programming practice
class ChefRobot
{
public:
	std::string CookFood(std::string what);

private:
	int speed = 5;
};

