#pragma once
#include <SDL.h>
#include "Constants.h"
#include "Texture.h"


class Tetromino
{
public:
	Tetromino(int type);
	void draw(SDL_Renderer * renderer);
	void move(int dx, int dy);
	void rotate();
	void getBlockColor(SDL_Renderer * Renderer);
	bool isBlock(int x, int y);
	int getType();
	int x();
	int y();
	//Tetromino operator = (Tetromino &temp);
private:
	Texture color;
	int type_;
	int x_;
	int y_;
	int angle;
};
