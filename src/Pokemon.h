#pragma once

#include <string>
#include <time.h>
#include "Texture.h"
#include "Vector2D.h"
#include "Constants.h"
#include "ListOf.h"
#include "Attack.h"
#include "Text_Manager.h"

extern SDL_Renderer* gRenderer;

class Pokemon
{
protected:
	//GRAPHIC ELEMENTS
	Texture body;
	Texture ground;
	Texture data;
	Texture name;
	Texture tLv;

	//GRAPHIC POSITIONING PARAMETERS
	Vector2D posData;
	Vector2D HP;
	Vector2D pName;
	Vector2D pLv;
	float groundMultiplyer;

	//DATA STRINGS
	string sName;
	string sLv;
	string pathBody;

	//DYMENSIONS
	int width;
	int height;

	//STATS
	int maxHP;
	int currentHP;
	int Lv;
	int attack;
	int defence;
	Constants::Types type;

	int attackId[4];
	ListOf<Attack> attacks;

	static Text_Manager pokedex;

	int dexNum;
public:	
	//CONSTRUCTION - DESTRUCTION
	Pokemon(int xHP = 0, int yHP = 0, int xName = 0, int yName = 0, int xLv = 0, int yLv = 0);
	~Pokemon(void);

	//MEDIA METHODS
	virtual bool loadFromFile();
	virtual void render(int x, int y);
	virtual void free();
	void loadStats();
	void setData(int d[]);

	float attacking(Pokemon& p, Attack a);

	//INTERFACE INLINE METHODS
	int getWidth(){return width;}
	int getHeight(){return height;}
	int getCurrentHP(){return currentHP;}
	void updateHP() { currentHP = maxHP; }
	ListOf<Attack> getAttacks() { return attacks; }
};



