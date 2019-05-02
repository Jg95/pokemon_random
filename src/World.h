#pragma once

#include "Fight.h"
#include "Adventure.h"
#include "Constants.h"

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color textColor;

class World
{
public:
	World();
	~World();

	bool init();
	bool loadMedia();
	void startScreen();
	void keyEvent(SDL_Event& e, bool& quit);
	void render();
	void close();

private:
	Constants::State state;
	Constants::State prevState;

	Fight fight;
	Adventure adventure;

	Texture startBack;
	Texture pokemonTitle;
	Texture hitmonlee;
	Texture instructions;

	Timer timer;
	int tic;
	int toc;

	ListOf<Animation> backPokemon;
	int backPkmnNum;
	int count;
};

	
