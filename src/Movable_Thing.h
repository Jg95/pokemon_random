#pragma once

#include "Thing.h"
#include "Constants.h"
#include "Animation.h"

class Movable_Thing: public Thing
{
public:
	Movable_Thing();
	~Movable_Thing();

	bool loadFromFile();
	bool loadFromSprite(Sprite sprite);
	bool move(Constants::Orientation inOrientation);
	void animate();
	void animate(Vector2D pos);
	void renderTallGrass();
	void setRenderTallGrass() { flagTallGrass = true; }
	void setOrientation(Constants::Orientation o) { orientation = o; }
	void setPos(Vector2D pos);
	virtual void setRelPos(Vector2D pos);
	Vector2D getPrevPos() { return prevPos; }

protected:
	Vector2D camPos;
	Vector2D prevPos;
	Constants::Orientation orientation = Constants::DOWN;
	Animation animation[Constants::ORIENTATION_TOTAL];

	bool flagTallGrass = false;
	Texture tallGrass;//Debería ser un puntero, cuando tengamos gestor de texturas

	int nclipsX = 3;
	int nclipsY = 1;

	int xvec[3] = { 0,64,128 };
	int yvec[3] = { 0,0,0 };
	int wvec[3] = { 64,64,64 };
	int hvec[3] = { 64,64,64 };
	int sequence[3] = { 1,0,2 };
	int dim = 3;
	int period = 50;
	int timeInterval[3] = { period,period * 2,period * 2 };

};





