#include "Sprite.h"

Sprite::Sprite(): numClipsX(0), numClipsY(0), clipW(0), clipH(0)
{
}

Sprite::~Sprite()
{
	delete clips;
}

//Set the rectangles in the sprite that are going to be the clips. 
//Parameters: number of clips, points (vector of x's and vector of y's) upper-left 
//corner of the rectangle, dimensions (vector of width's, vector of heigth's)
void Sprite::setClips(int inClipsX, int inClipsY, int *xvec, int *yvec, int *wvec, int *hvec)
{
	numClipsX = inClipsX;
	numClipsY = inClipsY;
	int numClips = inClipsX*inClipsY;

	if (numClips > 0)
	{
		clips = new SDL_Rect[numClips];

		for (int i = 0; i < numClips; i++)
		{
			(clips + i)->x = xvec[i];
			(clips + i)->y = yvec[i];
			(clips + i)->w = wvec[i];
			(clips + i)->h = hvec[i];
		}
	}
}

//Set the rectangles in the sprite that are going to be the clips. 
//Parameters: number of clips, points (vector of x's and vector of y's) upper-left 
//corner of the rectangle, dimensions (vector of width's, vector of heigth's)
void Sprite::setClips(int inClipsX, int inClipsY, int inWidth, int inHeight)
{
	numClipsX = inClipsX;
	numClipsY = inClipsY;
	int numClips = numClipsX*numClipsY;

	clipW = inWidth;
	clipH = inHeight;
	
	if (numClips > 0)
	{
		clips = new SDL_Rect[numClips];

		int count = 0;
		for (int i = 0; i < numClipsY; i++)
			for (int j = 0; j < numClipsX; j++)
			{
				(clips + count)->x = clipW * j;
				(clips + count)->y = clipH * i;
				(clips + count)->w = clipW;
				(clips + count)->h = clipH;

				count++;
			}
	}
}

//Render the numClip clip of the sprite, the number of the clip
//is the position in the sprite.
//Parameters: position (x,y), numClip
void Sprite::render(int x, int y, int numClip)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	currentClip = &clips[numClip];
	SDL_Rect renderQuad = { x, y, (currentClip->w), (currentClip->h) };
	SDL_RenderCopy(gRenderer, sdlTexture, currentClip, &renderQuad);
}

SDL_Rect Sprite::getClip(int numClip)
{
	return clips[numClip];
}