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
	void getExitCosts();
	void navigation(std::string in);
};