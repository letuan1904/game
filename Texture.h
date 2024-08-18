#pragma once
#include "Constants.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>


class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile(SDL_Renderer* renderer, std::string path);

	//Creates image from font string
	bool loadFromRenderedText(SDL_Renderer* renderer, TTF_Font* font, std::string textureText, SDL_Color textColor);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(SDL_Renderer* renderer, int x = 0, int y = 0, SDL_Rect* clip = NULL, bool stretchToScreen = false);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};
