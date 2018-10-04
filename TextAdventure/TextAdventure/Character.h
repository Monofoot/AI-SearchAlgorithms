#pragma once
#include<string>
#include"Location.h"

class Character
{
private:
	int fatigue = 100;
	std::string name;

public:
	Character(std::string charName);
	std::string getName();
};