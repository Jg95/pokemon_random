#pragma once

#include "Pokemon.h"
#include "Fight.h"

class Player: public Pokemon
{
	//GRAPHIC ELEMENTS
	Texture tmaxHP;
	Texture tcurrentHP;

	//GRAPHIC POSITIONING PARAMETERS
	Vector2D pmaxHP;
	Vector2D pcurrentHP;

	//DATA STRINGS
	string smaxHP;
	string scurrentHP;

	//ATTACKS

public:
	//CONSTRUCTION - DESTRUCTION
	Player();
	~Player(void);

	//GRAPHIC METHODS
	bool loadFromFile();
	void render(int x, int y);
	void free();
	void updateXData();
};

