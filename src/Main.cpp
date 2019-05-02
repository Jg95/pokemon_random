#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "World.h"

using namespace std;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;
SDL_Color textColor = { 0x5A, 0x5A, 0x5A };

World world;

int main(int argc, char* args[])
{
	bool startScreen = true;

	//Start up SDL and create window
	if (!world.init())
	{
		cout << "Failed to initialize!\n";
		return 0;
	}
	
	if (!world.loadMedia())
	{
		cout << "Failed to load media!" << endl;
		return 0;
	}

	bool quit = false;

	SDL_Event e;

	while (!quit)
	{
		SDL_RenderClear(gRenderer);

		//if (startScreen)
		//{
		//	SDL_PollEvent(&e);
		//	//if (SDL_PollEvent(&e) != 0)
		//	//startScreen = !(world.startScreen(e, quit));
		//}
		//else 
		//{
			//Handle events on queue
			if (SDL_PollEvent(&e) != 0)
				world.keyEvent(e, quit);

			world.render();
		//}

		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	world.close();

	return 0;
}
