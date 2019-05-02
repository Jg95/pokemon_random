#pragma once

#include "Sprite.h"

class Layer
{
public:
	Layer();
	~Layer();

	void print();
	void print(int x, int y, int w, int h);

	void setLayer(int w, int h, Sprite* s, int* seq, Constants::LayerType t);
	void setLayer(int w, int h, int* seq, Constants::LayerType t);
	void setLayerDim(int w, int h) { width = w; height = h; }
	void setSprite(Sprite* s) { sprite = s; }
	void setClipSequence(int* seq) { clipSequence = seq; }
	void setSequence(int* seq) { clipSequence = seq; }
	void setType(Constants::LayerType t) { type = t; }
	Constants::LayerType getType() { return type; }
	int getTile(Vector2D pos) { return clipSequence[pos.y * width + pos.x]; }

private:

	Constants::LayerType type;
	
	int* clipSequence;
	int* tileSequence;
	int width;
	int height;

	Sprite *sprite;

};

