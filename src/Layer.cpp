#include "Layer.h"

Layer::Layer()
{
}

Layer::~Layer()
{
}

void Layer::print()
{
	int count = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			sprite->render(64 * j, 64 * i, clipSequence[count] - 1);
			count++;
		}
}

void Layer::print(int x, int y, int w, int h)
{
	int tile = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			tile = ((i + y) * width) + (j + x);
			if (tile >= width*height) system("PAUSE");
			if (clipSequence[tile] != 0)
				sprite->render(64 * j, 64 * i, clipSequence[tile] - 1);
		}
}

void Layer::setLayer(int w, int h, Sprite* s, int* seq, Constants::LayerType t)
{
	setLayerDim(w, h);
	setSprite(s);
	setClipSequence(seq);
	setType(t);
}

void Layer::setLayer(int w, int h, int* seq, Constants::LayerType t)
{
	setLayerDim(w, h);
	setSequence(seq);
	setType(t);
}
