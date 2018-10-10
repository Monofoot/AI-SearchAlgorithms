#include"Game.h"

int main()
{
	Game newGame;
	newGame.mapSetup();

	while (newGame.printCurrentLocation().getCurrentLocation() != newGame.getDestination().getCurrentLocation())
	{
		newGame.getCurrentLocation();
		newGame.moveCharacter();
	}
}