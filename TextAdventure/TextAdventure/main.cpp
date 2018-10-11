#include"Game.h"
#include<iostream>

int main()
{
	Game newGame;
	newGame.mapSetup();

	while (newGame.printCurrentLocation().getCurrentLocation() != newGame.getGoal().getCurrentLocation())
	{
		newGame.getCurrentLocation();
		newGame.playerInput();
	}
}