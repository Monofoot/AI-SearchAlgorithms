#include"Location.h"
#include<string>

Location::Location() {}

Location::Location(std::string description)
{
	desc = description;

}

void Location::setExits(Location *n, Location *e, Location *s, Location *w)
{
	north = n;
	east = e;
	south = s;
	west = w;
}

void Location::getExits()
{
	std::cout << "To the North of you is: " << north->desc <<std::endl;
	std::cout << "To the East of you is: " << east->desc <<std::endl;
	std::cout << "To the South of you is: " << south->desc <<std::endl;
	std::cout << "To the West of you is: " << west->desc <<std::endl;
}

void Location::setExitCosts(int north, int south, int east, int west)
{
	exitCosts[0] = north;
	exitCosts[1] = south;
	exitCosts[2] = east;
	exitCosts[3] = west;
}