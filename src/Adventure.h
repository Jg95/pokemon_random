#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <time.h>
#include "Constants.h"
#include "Texture.h"
#include "Map.h"
#include "Player_Trainer.h"
#include "Movable_Trainer.h"
#include "Interaction.h"

class Adventure
{
public:
	Adventure() : route_0(20, 20), sceneDim(13, 11) { srand(time(NULL)); }
	~Adventure();

	bool loadFromFile();
	void events(SDL_Event& e, bool& quit);
	void setCameraPos();
	void render();
	void close();
	Constants::State getRequest() { return request; }
	void clearRequest() { request = Constants::ADVENTURE; }
	
private:
	Constants::State request = Constants::ADVENTURE;
	Constants::Orientation movement = Constants::STAND;
	Constants::Orientation t[4] = { Constants::STAND, Constants::DOWN, Constants::STAND, Constants::UP };
	Vector2D cameraPos;
	Vector2D sceneDim;
	Map route_0;
	Player_Trainer player;
	ListOf<Movable_Trainer> trainers;
};



