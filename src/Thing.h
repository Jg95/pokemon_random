#pragma once

#include "Vector2D.h"

class Thing
{
public:
	Thing();
	~Thing();

	virtual bool loadFromFile() = 0;
	Vector2D getPos() { return position; }

protected:
	Vector2D position;
};

