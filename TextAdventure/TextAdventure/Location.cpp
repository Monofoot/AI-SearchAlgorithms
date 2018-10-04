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

void Location::getExitCosts()
{
	std::cout << "Exit costs are: " << exitCosts[0] << std::endl;
	std::cout << "Exit costs are: " << exitCosts[1] << std::endl;
	std::cout << "Exit costs are: " << exitCosts[2] << std::endl;
	std::cout << "Exit costs are: " << exitCosts[3] << std::endl;
}

void Location::navigation(std::string in)
{
	std::string direction = in;

	if (direction == "n")
	{
		// character.location = north location
		std::cout << "Your new location is: n";
	}
	else if (direction == "e")
	{
		std::cout << "Your new location is: e";
	}
	else if (direction == "s")
	{
		std::cout << "Your new location is: s";
	}
	else if (direction == "w")
	{
		std::cout << "Your new location is: w";
	}
	else
	{
		std::cout << "You need to enter a valid direction. Enter either n, e, s or w in lower-case.";
	}
}