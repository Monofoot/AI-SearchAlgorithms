#include"Game.h"
#include"Character.h"
#include"World.h"
#include"Location.h"
#include<iostream>
#include<string>

// Construct the new game by designating rooms.
Game::Game():library("Library"), trollRoom("Troll's Room"), mysteriousRoom("Mysterious Room"),
			barracks("Barracks"), wellRoom("Well Room"), greatHall("Great Hall"), 
			bottleRoom("Bottle Room"), guardRoom("Guard Room"), dampCavern("Damp Cavern"),
			kitchen("Kitchen"), larder("Larder"), entrance("Entrance"), iceBox("Ice Box"),
			doom("Doom"), empty("Empty")
{
	address = &entrance;
	currentLocation = *address;
	cost = 0;
}

void Game::mapSetup()
{
	entrance.setExits(&dampCavern, &empty, &empty, &empty);
	entrance.setCost(2, 0, 0, 0);
	iceBox.setExits(&kitchen, &empty, &empty, &empty);
	iceBox.setCost(10, 0, 0, 0);
	guardRoom.setExits(&barracks, &dampCavern, &empty, &empty);
	guardRoom.setCost(2, 1, 0, 0);
	dampCavern.setExits(&wellRoom, &kitchen, &entrance, &guardRoom);
	dampCavern.setCost(1, 2, 2, 1);
	kitchen.setExits(&greatHall, &larder, &iceBox, &dampCavern);
	kitchen.setCost(1, 1, 2, 2);
	larder.setExits(&bottleRoom, &empty, &doom, &kitchen);
	larder.setCost(1, 0, 10, 1);
	barracks.setExits(&empty, &empty, &guardRoom, &empty);
	barracks.setCost(0, 0, 2, 0);
	wellRoom.setExits(&empty, &doom, &dampCavern, &empty);
	wellRoom.setCost(0, 3, 1, 0);
	greatHall.setExits(&bottleRoom, &mysteriousRoom, &kitchen, &trollRoom);
	greatHall.setCost(2, 4, 1, 2);
	bottleRoom.setExits(&empty, &empty, &larder, &greatHall);
	bottleRoom.setCost(0, 0, 1, 2);
	trollRoom.setExits(&library, &mysteriousRoom, &greatHall, &mysteriousRoom);
	trollRoom.setCost(1, 3, 2, 0);
	mysteriousRoom.setExits(&library, &empty, &greatHall, &trollRoom);
	mysteriousRoom.setCost(3, 0, 4, 3);
	library.setExits(&empty, &trollRoom, &mysteriousRoom, &empty);
	library.setCost(0, 1, 3, 0);

	// setDestination sets the end-goal of the game.
	setDestination(mysteriousRoom);
}

void Game::getCurrentLocation()
{
	currentLocation = *address;
	std::cout << currentLocation.getCurrentLocation() << std::endl;
	currentLocation.getExits();
}

void Game::moveCharacter()
{
	char x;
	std::cin >> x;

	if (x != 'n' && x != 'e' && x != 's' && x != 'w' )
	{
		std::cout << "Incorrect location. Please either input n, e, s or w." << std::endl;
	}
	if (currentLocation.getDirection(x) != &empty)
	{
		address = currentLocation.getDirection(x);
		addCost(currentLocation.getCost(x));
		std::cout << "Cost: " << cost << std::endl;
	}
}

void Game::setDestination(Location x)
{
	destination = x;
}

Location Game::getDestination()
{
	return destination;
}

Location Game::printCurrentLocation()
{
	return currentLocation;
}

void Game::setCurrentLocation(Location l)
{
	currentLocation = l;
}

int Game::getCost()
{
	return cost;
}

void Game::addCost(int addition)
{
	cost += addition;
}

Game::~Game()
{}