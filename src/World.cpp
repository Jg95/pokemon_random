#include "World.h"

World::World(): state(Constants::START_SCREEN)
{
	tic = timer.millis();
	backPkmnNum = 10;
	for (int i = 0; i < backPkmnNum; i++)
		backPokemon += new Animation;
	count = 0;
}

World::~World()
{
	startBack.free();
}

bool World::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		cout << "Warning: Linear texture filtering not enabled!" << endl;

	gWindow = SDL_CreateWindow("Pokemon Random", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (gWindow == NULL)
	{
		cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (gRenderer == NULL)
	{
		cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}
	
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
		system("pause");
		return false;
	}

	if (TTF_Init() == -1)
	{
		cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
		system("pause");
		return false;
	}
	
	gFont = TTF_OpenFont("../img/Texturas/pokemon_ingame_bold.ttf", 28);

	if (gFont == NULL)
	{
		cout << "Failed to load image font! SDL_ttf Error: " << TTF_GetError() << endl;
		system("pause");
		return false;
	}
	
	return true;
}

bool World::loadMedia()
{
	if (!fight.loadMedia() || !adventure.loadFromFile())
		return false;

	if (!startBack.loadFromFile("../img/Texturas/Wallpapers/pidgeot.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[0].loadFromFile("../img/Texturas/Wallpapers/pidgeot.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[1].loadFromFile("../img/Texturas/Wallpapers/aerodactyl.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[2].loadFromFile("../img/Texturas/Wallpapers/gardevoir.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[3].loadFromFile("../img/Texturas/Wallpapers/mew.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[4].loadFromFile("../img/Texturas/Wallpapers/ninetails.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[5].loadFromFile("../img/Texturas/Wallpapers/persian.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[6].loadFromFile("../img/Texturas/Wallpapers/skarmory.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[7].loadFromFile("../img/Texturas/Wallpapers/swellow.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[8].loadFromFile("../img/Texturas/Wallpapers/tropius.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!backPokemon[9].loadFromFile("../img/Texturas/Wallpapers/wingull.png"))
	{
		cout << "Failed to load startBack texture image" << endl;
		return false;
	}

	if (!pokemonTitle.loadFromFile("../img/Texturas/pokemon.png"))
	{
		cout << "Failed to load Title texture image!" << endl;
		return false;
	}

	textColor = { 0xFF, 0xCB, 0x05 };
	if (!instructions.loadFromRenderedText("Press 'a' to start"))
	{
		cout << "Failed to load instructions from text!" << endl;
		return false;
	}
	textColor = { 0x5A, 0x5A, 0x5A };

	if (!hitmonlee.loadFromFile("../img/Texturas/hitmonlee.png"))
	{
		cout << "Failed to load hitmonlee texture image!" << endl;
		return false;
	}

	return true;
}

void World::startScreen()
{
	//startBack.render(0, 0);
}

void World::keyEvent(SDL_Event& e, bool& quit)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_a:
		if (state == Constants::START_SCREEN)
		{
			state = Constants::ADVENTURE;
			break;
		}
		break;
	case SDLK_m:
		state = Constants::ADVENTURE;
		break;
	case SDLK_n:
		state = Constants::FIGHT;
		break;
	default:
		break;
	}

	if (state == Constants::START_SCREEN)
		startScreen();
	if (state == Constants::FIGHT)
		fight.events(e, quit);
	if (state == Constants::ADVENTURE)
		adventure.events(e, quit);
}

void World::render()
{
	SDL_RenderClear(gRenderer);
	if (state == Constants::FIGHT)
		fight.render();
	if (state == Constants::ADVENTURE)
		adventure.render();
	if (state == Constants::START_SCREEN)
	{
		startBack.render(0, 0);
		if (backPokemon[count].isEnded())
		{
			count++;
			if (count == 10)
				count = 0;
			int seq[4] = { 0, 0, 0, 0 };
			int tinterval[4] = { 100, 100, 100, 100 };
			backPokemon[count].setSequence(4, seq, tinterval);
			backPokemon[count].setSpaceInterval(Vector2D(0, 0), Vector2D(200, 0));
			backPokemon[count].start();
		}
		else
			backPokemon[count].animate();
		pokemonTitle.render(50, 50);
		instructions.render(150, 225);
		hitmonlee.render(150, 300);
	}
	if (state == Constants::TRANSITION)
	{
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		toc = timer.millis() - tic;
		if (toc >= 250)
		{
			switch (prevState)
			{
			case Constants::ADVENTURE:
				state = Constants::FIGHT;
				tic = timer.millis();
				break;
			case Constants::FIGHT:
				state = Constants::ADVENTURE;
				tic = timer.millis();
				break;
			}
		}
	}

	if (fight.getRequest() == Constants::ADVENTURE)
	{
		tic = timer.millis();
		state = Constants::TRANSITION;
		prevState = Constants::FIGHT;
		fight.clearRequest();
	}
	if (adventure.getRequest() == Constants::FIGHT)
	{
		tic = timer.millis();
		state = Constants::TRANSITION;
		prevState = Constants::ADVENTURE;
		adventure.clearRequest();
	}
}

void World::close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	//Free resources and close SDL
	adventure.close();
	fight.close();
}
