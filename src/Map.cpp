#include "Map.h"

Map::~Map()
{
}

void Map::loadFromFileT()
{
	map.loadFromFile("../img/sprites/Route_0.png");

	for (int i = 0; i < numLayers; i++)
		layers += new Layer;
	layers[0].setLayer(width, height, walkable, Constants::WALKABLE);
	layers[1].setLayer(width, height, notwalkable, Constants::NOTWALKABLE);
	layers[2].setLayer(width, height, water, Constants::WATER);
	layers[3].setLayer(width, height, tallgrass, Constants::TALLGRASS);
	layers[4].setLayer(width, height, entrance, Constants::ENTRANCE);
}

void Map::loadFromFile()
{
	background.loadFromFile("../img/sprites/map.png");
	background.setClips(spriteWidth, spriteHeight, 64, 64);

	for (int i = 0; i < numLayers; i++)
		layers += new Layer;
	layers[0].setLayer(width, height, &background, walkable, Constants::WALKABLE);
	layers[1].setLayer(width, height, &background, notwalkable, Constants::NOTWALKABLE);
	layers[2].setLayer(width, height, &background, water, Constants::WATER);
	layers[3].setLayer(width, height, &background, tallgrass, Constants::TALLGRASS);
	layers[4].setLayer(width, height, &background, entrance, Constants::ENTRANCE);
}

void Map::printMap(int x, int y)
{
	map.render(x * Constants::TILE_DIM, y * Constants::TILE_DIM);
}

void Map::printMap()
{
	for (int i = 0; i < numLayers; i++)
		layers[i].print();
}


void Map::printSubMap(int x, int y, int w, int h)
{
	for (int i = 0; i < numLayers; i++)
		layers[i].print(x,y,w,h);
}
