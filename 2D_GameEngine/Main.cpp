#include "Game.h"

Game *game = nullptr;


int main(int argc, char *args[]) {

	const int FPS = 60;
	const int frameDelay = 4000 / FPS;

	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handelEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}

	game->clean();

	return 0; 
}