#pragma once
#include<iostream>
#include<string>
#include<vector>

class Location
{
private:
	std::string desc;
	Location *north;
	Location *east;
	Location *south;
	Location *west;
	int exitCosts[4];

public:
	Location();
	Location(std::string description);
	void setExits(Location *n, Location *e, Location *s, Location *w);
	//For debugging currently - remove after
	void getExits();
	std::string getDesc()
	{
		return desc;
	}
	void setExitCosts(int north, int east, int south, int west);
	void getExitCosts()
	{
		std::cout << "Exit costs are: " << exitCosts[0] << std::endl;
		std::cout << "Exit costs are: " << exitCosts[1] << std::endl;
		std::cout << "Exit costs are: " << exitCosts[2] << std::endl;
		std::cout << "Exit costs are: " << exitCosts[3] << std::endl;
	}
};