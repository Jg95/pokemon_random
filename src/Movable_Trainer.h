#pragma once

#include "Movable_Thing.h"

class Movable_Trainer: public Movable_Thing
{
public:
	Movable_Trainer();
	Movable_Trainer(Vector2D pos) : trajIndex(0), trajDim(0) { position = pos; }
	Movable_Trainer(int posx, int posy) : trajIndex(0), trajDim(0) { position.x = posx;	position.y = posy; }
	~Movable_Trainer();

	void setSprite();
	void setTrajectory(int dim, Constants::Orientation *t);
	void walk();

private:
	Constants::Orientation *trajectory;
	int trajDim;
	int trajIndex;

};





