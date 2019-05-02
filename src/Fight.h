#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "Constants.h"
#include "Vector2D.h"
#include "ListOf.h"
#include "Pokemon.h"
#include "Player.h"
#include "Enemy.h"
#include "Dialog.h"
#include "Timer.h"

using namespace std;

class Fight
{
	//SCENE
	Texture background;
	Dialog dialog;

	ListOf<Pokemon> pokemon;
	float effectiveness;

	static Text_Manager info;

	Constants::FightState state;
	Constants::State request;
	bool busy;

	//STATE COORDINATION ATRIBUTES
	Vector2D cursor;
	ListOf<Vector2D> option;
	Constants::Orientation direction;
	Timer timer;
	int tic;
	int toc;
public:
	//CONSTRUCTION - DESTRUCTION
	Fight(void);
	~Fight(void);

	//START-STOP METHODS
	void close();

	//MEDIA METHODS
	void loadStats();
	bool loadMedia();
	void render();

	//EVENT MANAGEMENT
	void events(SDL_Event &e, bool &quit);
	void coordinateStates(SDL_Event &e);
	void moveCursor();

	Constants::State getRequest() { return request;}
	void clearRequest() { request = Constants::FIGHT; }
};

