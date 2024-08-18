#include "Board.h"

Board::Board(int bestScore) :
	data{ {0} },
	score(0),
	line(0),
	highScore(bestScore)
{
}

Board::Board() :
	data{ {0} },
	score(0),
	line(0),
	highScore(0)
{
}

void Board::draw(SDL_Renderer *Renderer)
{
	//draw lines of board
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 0xff);
	SDL_RenderDrawLine(Renderer, 0, 0, 0, SCREEN_HEIGHT);
	SDL_RenderDrawLine(Renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
	// draw blocks of board
	for (auto x = 0; x < WIDTH; ++x)
	  for (auto y = 0; y < HEIGHT; ++y)
	  {
		  if (data[x][y])
		  {
			  switch (data[x][y])
			  {
			  case I:
				  block.red.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case J:
				  block.yellow.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case L:
				  block.skyblue.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case O:
				  block.blue.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case S:
				  block.purple.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case T:
				  block.orange.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  case Z:
				  block.green.render(Renderer, x * SQUARE_SIDE + 1, y * SQUARE_SIDE + 1);
				  break;
			  }
		  }
	  }
}

void Board::drawNext(SDL_Renderer *Renderer, Tetromino nextTetromino) {
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			if (nextTetromino.isBlock(x, y)) {
				switch (nextTetromino.getType())
				{
				case I:
					block.red.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case J:
					block.yellow.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case L:
					block.skyblue.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case O:
					block.blue.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case S:
					block.purple.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case T:
					block.orange.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				case Z:
					block.green.render(Renderer, (3 * SCREEN_WIDTH / 2 - 4 * SQUARE_SIDE) / 2 + x * SQUARE_SIDE, (SCREEN_HEIGHT / 2 - 4 * SQUARE_SIDE) / 2 + y * SQUARE_SIDE);
					break;
				}
			}
		}
	}
}

bool Board::isCollision( Tetromino &tetromino)
{
  for (int x = 0; x < 4; ++x)
    for (int y = 0; y < 4; ++y)
      if (tetromino.isBlock(x, y))
      {
        int X = tetromino.x() + x;			// the real coordinate X,Y on the Board
        int Y = tetromino.y() + y;
        if (X < 0 || X >= WIDTH || Y < 0 || Y >= HEIGHT)
          return true;
        if (data[X][Y])
          return true;
      }
  return false;
}

void Board::deleteLines( Tetromino &tetromino)
{
  //update board
  for (int x = 0; x < 4; ++x)
    for (int y = 0; y < 4; ++y)
      if (tetromino.isBlock(x, y))
        data[tetromino.x() + x][tetromino.y() + y] = (int)tetromino.getType();
  //delete lines (if any)
  int k = HEIGHT - 1;
  int countLines = 0;
  for (int row = HEIGHT - 1; row > 0; row--)
  {
	  int count = 0;
	  for (int col = 0; col < WIDTH; col++)		//check the whole row
	  {
		  if (data[col][row]) count++;			//data != 0 means it's block
		  data[col][k] = data[col][row];
	  }
	  if (count == WIDTH) 
		  countLines++;
	  else k--;									//if it's not line then k keep up with row
  }
  line += countLines;
  switch (countLines) {
  case 1:
	  score += 10;
	  break;
  case 2:
	  score += 30;
	  break;
  case 3:
	  score += 50;
	  break;
  case 4:
	  score += 100;
	  break;
  default:
	  break;
  }

}

int Board::getScore() {
	return score;
}

int Board::getHighScore() {
	highScore = highScore < score ? score : highScore;
	return highScore;
}

int Board::getLines() {
	return line;
}

int Board::delayTime() {
	if (score >= 1000) return 100;
	if (score >= 500) return 200;
	if (score >= 200) return 300;
	if (score >= 100) return 400;
	return 500;
}