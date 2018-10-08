#include"Character.h"
#include"Location.h"
#include<string>
#include<iostream>

Character::Character(std::string charName)
{
	
	name = charName;
}

std::string Character::getName()
{
	return name;
}