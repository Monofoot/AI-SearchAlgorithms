#pragma once
#include<string>
#include"Location.h"

class Game
{
private:
	// List the locations. Add to this list for any new locations.
	Location library, trollRoom, mysteriousRoom, barracks, wellRoom, greatHall;
	Location bottleRoom, guardRoom, dampCavern, kitchen, larder;
	Location entrance, iceBox, doom, empty;
	int cost;
	Location currentLocation;
	Location *address;
	Location destination;

public:
	Game();
	void mapSetup();
	void getCurrentLocation();
	void moveCharacter();
	void setDestination(Location x);
	Location getDestination();
	Location printCurrentLocation();
	void setCurrentLocation(Location l);
	int getCost();
	void addCost(int addition);
	~Game();
};