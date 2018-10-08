#pragma once
#include<string>
#include"Location.h"

class Game
{
private:
	Location *currentLocation;
public:
	void navigation(std::string in);
	void mainRoutine();
};