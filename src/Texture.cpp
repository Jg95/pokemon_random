#include "Texture.h"

Texture::Texture()
{
	sdlTexture = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture()
{
	free();
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(sdlTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(sdlTexture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(sdlTexture, alpha);
}

bool Texture::loadFromFile( string path)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << endl;
		system("pause");
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "Unable to create texture from " << path.c_str() << "!SDL Error : " << SDL_GetError() << endl;
			system("pause");
		}
		else
		{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	sdlTexture = newTexture;
	return sdlTexture != NULL;
}


bool Texture::loadFromRenderedText(string textureText)
{
	free();
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << endl;
		system("pause");
	}
	else
	{
		sdlTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (sdlTexture == NULL)
		{
			cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << endl;
			system("pause");
		}
		else
		{
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return sdlTexture != NULL;
}

void Texture::render(int x, int y, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, (clip->w), (clip->h) };
	SDL_RenderCopy(gRenderer, sdlTexture, clip, &renderQuad);
}

void Texture::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, width, height };
	SDL_RenderCopy(gRenderer, sdlTexture, NULL, &renderQuad);
}

void Texture::free()
{
	if (sdlTexture != NULL)
	{
		SDL_DestroyTexture(sdlTexture);
		sdlTexture = NULL;
		width = 0;
		height = 0;
	}
}

