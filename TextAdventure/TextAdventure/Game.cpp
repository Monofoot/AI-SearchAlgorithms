#include"Game.h"
#include"Character.h"
#include"World.h"
#include"Location.h"
#include<iostream>
#include<string>

void Game::mainRoutine()
{
	// Declare each location.
	Location library("Library");
	Location trollRoom("Troll's Room");
	Location mysteriousRoom("Mysterious Room");
	Location barracks("Barracks");
	Location wellRoom("Well Room");
	Location greatHall("Great Hall");
	Location bottleRoom("Bottle Room");
	Location guardRoom("Guard Room");
	Location dampCavern("Damp Cavern");
	Location kitchen("Kitchen");
	Location larder("Larder");
	Location entrance("Entrance");
	Location iceBox("Ice Box");
	Location doom("Doom.");
	Location empty("Empty.");

	currentLocation = &entrance;

	// Each location need to be instantiated with four parameters.
	// First we set exits, which requires pointers to the north,
	// east, south and west of each room.
	// Secondly we need to set the corresponding exit costs, where
	// int is (north, east, south, west).
	entrance.setExits(&dampCavern, &empty, &empty, &empty);
	entrance.setExitCosts(2, 0, 0, 0);
	iceBox.setExits(&kitchen, &empty, &empty, &empty);
	iceBox.setExitCosts(10, 0, 0, 0);
	guardRoom.setExits(&barracks, &dampCavern, &empty, &empty);
	guardRoom.setExitCosts(2, 1, 0, 0);
	dampCavern.setExits(&wellRoom, &kitchen, &entrance, &guardRoom);
	dampCavern.setExitCosts(1, 2, 2, 1);
	kitchen.setExits(&greatHall, &larder , &iceBox, &dampCavern);
	kitchen.setExitCosts(1, 1, 2, 2);
	larder.setExits(&bottleRoom, &empty, &doom, &kitchen);
	larder.setExitCosts(1, 0, 10, 1);
	barracks.setExits(&empty, &empty, &guardRoom, &empty);
	barracks.setExitCosts(0, 0, 2, 0);
	wellRoom.setExits(&empty, &doom, &dampCavern, &empty);
	wellRoom.setExitCosts(0, 3, 1, 0);
	greatHall.setExits(&bottleRoom, &mysteriousRoom, &kitchen, &trollRoom);
	greatHall.setExitCosts(2, 4, 1, 2);
	bottleRoom.setExits(&empty, &empty, &larder, &greatHall);
	bottleRoom.setExitCosts(0, 0, 1, 2);
	trollRoom.setExits(&library, &mysteriousRoom, &greatHall, &mysteriousRoom);
	trollRoom.setExitCosts(1, 3, 2, 0);
	mysteriousRoom.setExits(&library, &empty, &greatHall, &trollRoom);
	mysteriousRoom.setExitCosts(3, 0, 4, 3);
	library.setExits(&empty, &trollRoom, &mysteriousRoom, &empty);
	library.setExitCosts(0, 1, 3, 0);

	// Set up the character and world.
	std::string characterName;
	std::cout << "Welcome! What's your name?..." << std::endl;
	std::cin >> characterName;
	Character player(characterName);
	World world;
	std::cout << "Welcome, " << player.getName() << "." << std::endl;
	std::cout << "You are at the beginning of a great adventure." << std::endl <<
		"To your north is the entrance of an ominous structure of rocks," << std::endl <<
		"something akin to a cave entrance. Where do you plan on heading?" << std::endl;

	bool gameRunning = true;
	while (gameRunning == true)
	{
		currentLocation->getExits();
		std::cout << "Where would you like to turn?" << std::endl;

		std::string input;
		std::cin >> input;

		// Need a way to change this to player.location. maybe.
		// WORK ON NAVIGATION!!!
		navigation(input);
	}
}

void Game::navigation(std::string in)
{
	std::string direction = in;

	if (direction == "n")
	{
		std::cout << "Your new location is: n" << std::endl << std::endl;
		std::cout << currentLocation->getDesc();
	}
	else if (direction == "e")
	{
		std::cout << "Your new location is: e" << std::endl << std::endl;
	}
	else if (direction == "s")
	{
		std::cout << "Your new location is: s" << std::endl << std::endl;
	}
	else if (direction == "w")
	{
		std::cout << "Your new location is: w" << std::endl << std::endl;
	}
	else
	{
		std::cout << "You need to enter a valid direction. Enter either n, e, s or w in lower-case." << std::endl << std::endl;
	}
}