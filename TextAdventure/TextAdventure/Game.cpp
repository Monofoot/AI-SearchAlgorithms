#include"Game.h"
#include"Character.h"
#include"World.h"
#include"Location.h"
#include<iostream>
#include<string>

void Game::mainRoutine()
{
	// Set the locations in a vector.
	std::vector<Location> locations;

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

	library.setExits(&empty, &trollRoom, &mysteriousRoom, &barracks);
	library.setExitCosts(0, 3, 1, 0);

	// Set up the character and world.
	std::string characterName;
	std::cout << "Welcome! What's your name?..." << std::endl;
	std::cin >> characterName;
	Character player(characterName);
	World world;
	std::cout << "Welcome, " << player.getName() << "." << std::endl;

	

	bool gameRunning = true;
	while (gameRunning == true)
	{
		std::cout << "You are at the beginning of a great adventure." << std::endl <<
			"To your north is the entrance of an ominous structure of rocks," << std::endl <<
			"something akin to a cave entrance. Where do you plan on heading?" << std::endl;
		library.getExits();
		std::cout << "Where would you like to turn?" << std::endl;

		std::string stop;
		std::cin >>  stop;
	}

}