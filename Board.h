#pragma once
#include "Constants.h"
#include "Tetromino.h"
#include "Texture.h"
#include "Block.h"
#include <SDL.h>


class Board
{
public:
	Board(int bestScore);
	Board();
	void draw(SDL_Renderer *Renderer);
	void drawNext(SDL_Renderer *Renderer,Tetromino nextTetromino);
	bool isCollision(Tetromino &tetromino);
	void deleteLines(Tetromino &tetromino);
	int getScore();
	int getHighScore();
	int getLines();
	int delayTime();
	Block block;
private:
	Texture color;
	int highScore;
	int score;
	int line;
	int data[WIDTH][HEIGHT+3];
};
