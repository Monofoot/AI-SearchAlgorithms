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
	// address is the pointer used throughout the game to designate a location. Declare address
	// with a pointer to the entrance because this is where the game starts.
	address = &entrance;
	currentLocation = *address;
	// Set the cost int to 0.
	cost = 0;
}

// mapSetup lists each location's adjacent exits and the cost to travel to them.
// Locations should be listed as:
// location.setExits(&north, &east, &south, &west);
// location.setCost(int, int, int, int);
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

	// setGoal is the goal of the game. When currentLocation equals setDestination
	// the game loop ends.
	std::cout << "The goal of this game is to reach the " << mysteriousRoom.getCurrentLocation() << std::endl;
	setGoal(mysteriousRoom);
}

void Game::getCurrentLocation()
{
	// Set currentLocation to the address pointer.
	currentLocation = *address;
	// Access the getCurrentLocation function inside of the current location.
	std::cout << "Current location: " << currentLocation.getCurrentLocation() << std::endl;
	// Call getExits() from said current location. BREAK THIS UP INTO A USER REQUEST.
	currentLocation.getExits();
}

void Game::playerInput()
{
	// Start by asking the user which direction they want to head.
	std::cout << "Please enter your direction. Your choices are n, e, s or w." << std::endl;
	std::cout << "Entering d will give you a reminder of your adjacent locations." << std::endl;
	char x;
	std::cin >> x;

	if (x != 'n' && x != 'e' && x != 's' && x != 'w' && x != 'd')
	{
		std::cout << "Incorrect location. Please either input n, e, s or w." << std::endl;
		std::cout << "For a reminder, input d." << std::endl;
		std::cin >> x;
	}
	if (x == 'd')
	{
		currentLocation.getExits();
		std::cout << "Please enter your direction. Your choices are n, e, s or w." << std::endl;
		std::cin >> x;
	}
	if (currentLocation.getDirection(x) != &empty)
	{
		address = currentLocation.getDirection(x);
		addCost(currentLocation.getCost(x));
		std::cout << "Moving here cost: " << currentLocation.getCost(x)  << std::endl;
		std::cout << "Your total cost is: " << cost << std::endl;
	}
}

// Set a new goal. This function will be invoked when setting the end-point of the game.
void Game::setGoal(Location x)
{
	destination = x;
}

// Return the goal.
Location Game::getGoal()
{
	return destination;
}

// Return the player's current location.
// Why isn't this get player's location?
Location Game::printCurrentLocation()
{
	return currentLocation;
}

// Set the player's current location.
void Game::setCurrentLocation(Location l)
{
	currentLocation = l;
}

// Get cost. Is this the total cost or the current cost? Explain this.
int Game::getCost()
{
	return cost;
}

// Parse addition to cost.
void Game::addCost(int addition)
{
	cost += addition;
}

Game::~Game()
{}