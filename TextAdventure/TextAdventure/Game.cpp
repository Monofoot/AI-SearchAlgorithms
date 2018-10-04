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
		entrance.getExits();
		std::cout << "Where would you like to turn?" << std::endl;

		std::string input;
		std::cin >> input;

		// This needs to not be entrance. Need a way to change this to player.location.
		entrance.navigation(input);
	}

}