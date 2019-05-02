#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern TTF_Font* gFont;
extern SDL_Color textColor;

class Texture
{
public:
	Texture();
	~Texture();

	int getWidth() { return width; }
	int getHeight() { return height; }

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	
	bool loadFromFile(string path);
	bool loadFromRenderedText(string textureText);

	void render(int x, int y, SDL_Rect* clip);
	virtual void render(int x, int y);

	void free();

protected:
	SDL_Texture* sdlTexture;
	int width;
	int height;
};

