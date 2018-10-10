#include"Location.h"
#include<string>
#include<iostream>

Location::Location() {}

Location::Location(std::string n)
{
	name = n;

}

void Location::setExits(Location *n, Location *e, Location *s, Location *w)
{
	north = n;
	east = e;
	south = s;
	west = w;
}

void Location::setCost(int north, int south, int east, int west)
{
	costNorth = north;
	costEast = east;
	costSouth = south;
	costWest = west;
}

Location* Location::getDirection(char heading)
{
	if (heading == 'n')
	{
		return north;
	}
	else if (heading == 'e')
	{
		return east;
	}
	else if (heading == 's')
	{
		return south;
	}
	else if (heading == 'w')
	{
		return west;
	}
	else
	{
		std::cout << "Incorrect direction. Please only type n, e, s or w." << std::endl;
	}
}

int Location::getCost(char heading)
{
	if (heading == 'n')
	{
		return costNorth;
	}
	else if (heading == 'e')
	{
		return costEast;
	}
	else if (heading == 's')
	{
		return costSouth;
	}
	else if (heading == 'w')
	{
		return costWest;
	}
}

void Location::getExits()
{
	std::cout << "To the North of you is: " << north->name << std::endl;
	std::cout << "To the East of you is: " << east->name << std::endl;
	std::cout << "To the South of you is: " << south->name << std::endl;
	std::cout << "To the West of you is: " << west->name << std::endl;
}

std::string Location::getCurrentLocation()
{
	return name;
}

Location::~Location()
{}