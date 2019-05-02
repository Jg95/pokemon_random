#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector2D.h"
#include "Constants.h"
#include "Texture.h"

using namespace std;

class Sprite: public Texture
{
public:
	Sprite();
	~Sprite();

	void setClips(int inClipsX, int inClipsY, int *xvec, int *yvec, int *wvec, int *hvec);
	void setClips(int inClipsX, int inClipsY, int inWidth, int inHeight);
	virtual void render(int x, int y, int numClip);
	SDL_Rect getClip(int numClip);
	int getNumClipsX() { return numClipsX; }
	int getNumClipsY() { return numClipsY; }

protected:
	SDL_Rect* clips;
	SDL_Rect* currentClip;
	int numClipsX;
	int numClipsY;
	int clipW;
	int clipH;
};



