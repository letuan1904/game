#include "Tetromino.h"
Tetromino::Tetromino(int type):
  type_(type),
  x_(3),
  y_(0),
  angle(0)
{
}

void Tetromino::draw(SDL_Renderer *renderer)
{
  for (auto x = 0; x < 4; ++x)
    for (auto y = 0; y < 4; ++y)
      if (isBlock(x, y))
      {
		  color.render(renderer, (x + x_)*SQUARE_SIDE + 1, (y + y_)*SQUARE_SIDE + 1);
      }
}

void Tetromino::move(int dx, int dy)
{
  x_ += dx;
  y_ += dy;
}

void Tetromino::rotate()
{
  angle ++;
  angle %= 4;
}

void Tetromino::getBlockColor(SDL_Renderer * Renderer) {
	switch (type_)
	{
	case I:
		color.loadFromFile(Renderer, "Stock/red.jpg");
		break;
	case J:
		color.loadFromFile(Renderer, "Stock/yellow.jpg");
		break;
	case L:
		color.loadFromFile(Renderer, "Stock/skyblue.jpg");
		break;
	case O:
		color.loadFromFile(Renderer, "Stock/blue.jpg");
		break;
	case S:
		color.loadFromFile(Renderer, "Stock/purple.jpg");
		break;
	case T:
		color.loadFromFile(Renderer, "Stock/orange.jpg");
		break;
	case Z:
		color.loadFromFile(Renderer, "Stock/green.jpg");
		break;
	}
}

bool Tetromino::isBlock(int x, int y) 
{
  const int Shapes[NUMBER_OF_TYPES ][NUMBER_OF_ANGLES][4][4] = {
	// I
    {
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
		},
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
		}
	},		
	// J
	{
		{
			{2,0,0,0},
			{2,2,2,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,2,2,0},
			{0,2,0,0},
			{0,2,0,0},
			{0,0,0,0},
		},
		{
			{0,0,0,0},
			{2,2,2,0},
			{0,0,2,0},
			{0,0,0,0},
		},
		{
			{0,0,2,0},
			{0,0,2,0},
			{0,2,2,0},
			{0,0,0,0},
		}
	},		
	// L
	{
		{
			{0,0,3,0},
			{3,3,3,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,3,0,0},
			{0,3,0,0},
			{0,3,3,0},
			{0,0,0,0},
		},
		{
			{3,3,3,0},
			{3,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,3,3,0},
			{0,0,3,0},
			{0,0,3,0},
			{0,0,0,0},
		}
	 },	  
	// O
	{
		{
			{0,4,4,0},
			{0,4,4,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,4,4,0},
			{0,4,4,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,4,4,0},
			{0,4,4,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,4,4,0},
			{0,4,4,0},
			{0,0,0,0},
			{0,0,0,0},
		},
	 },	   
	// S
	{
		{
			{5,5,0,0},
			{0,5,5,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,0,5,0},
			{0,5,5,0},
			{0,5,0,0},
			{0,0,0,0},
		},
		{
			{5,5,0,0},
			{0,5,5,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,0,5,0},
			{0,5,5,0},
			{0,5,0,0},
			{0,0,0,0},
		},
	},		
	// T
	{
		{
			{0,6,0,0},
			{6,6,6,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,6,0,0},
			{0,6,6,0},
			{0,6,0,0},
			{0,0,0,0},
		},
		{
			{0,0,0,0},
			{6,6,6,0},
			{0,6,0,0},
			{0,0,0,0},
		},
		{
			{0,6,0,0},
			{6,6,0,0},
			{0,6,0,0},
			{0,0,0,0},
		}
	},	
	// Z
	{
		{
			{0,7,7,0},
			{7,7,0,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,7,0,0},
			{0,7,7,0},
			{0,0,7,0},
			{0,0,0,0},
		},
		{
			{0,7,7,0},
			{7,7,0,0},
			{0,0,0,0},
			{0,0,0,0},
		},
		{
			{0,7,0,0},
			{0,7,7,0},
			{0,0,7,0},
			{0,0,0,0},
		},
	}
  };
  return Shapes[type_-1][angle][y][x] != 0;
}

int Tetromino::getType()  {
	return type_;
}

int Tetromino::x() 
{
  return x_;
}

int Tetromino::y() 
{
  return y_;
}