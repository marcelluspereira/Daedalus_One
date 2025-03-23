// Daedalus_One.cpp : Defines the entry point for the application.
//

#include "Daedalus_One.h"
#include "Game.h"

using namespace std;
using namespace daedalus;

int main()
{
	// Init engine
	Game* game = new Game;

	game->Init();


	//Game loop
	while (game->running()) {
		// Update
		game->update();

		// Render
		game->render();
	}

	// EOL
	return 0;
}
