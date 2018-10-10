#include"Character.h"

Character::Character()
{}

void Character::setCurrentLocation(Location location)
{
	currentLocation = location;
}

Location Character::getCurrentLocation()
{
	return currentLocation;
}

Character::~Character()
{}