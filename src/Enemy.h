#pragma once

#include "Pokemon.h"

class Enemy: public Pokemon
{
public:
	Enemy();
	~Enemy(void);

	bool loadFromFile();
};

