#pragma once
#include<string>

class Location
{
private:
	std::string name = " ";
	Location *north;
	Location *east;
	Location *south;
	Location *west;
	int costNorth, costEast, costSouth, costWest;

public:
	Location();
	Location(std::string n);
	void setExits(Location *n, Location *e, Location *s, Location *w);
	void setCost(int, int, int, int);
	Location* getDirection(char);
	int getCost(char);
	void getExits();
	std::string getCurrentLocation();
	~Location();
};