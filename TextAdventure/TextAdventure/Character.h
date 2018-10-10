#pragma once
#include"Location.h"

class Character
{
private:
	Location currentLocation;

public:
	Character();
	void setCurrentLocation(Location);
	Location getCurrentLocation();
	~Character();
};