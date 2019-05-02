#pragma once

#include "Map.h"

class Map_Manager
{
public:
	Map_Manager();
	~Map_Manager();

private:
	ListOf<Map> maps;
};

