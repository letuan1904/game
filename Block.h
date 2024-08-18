#pragma once
#include "Texture.h"

class Block  {
public:
	Texture red, yellow, skyblue, blue, purple, orange, green;
	Block();
	~Block();
	void loadBlocks(SDL_Renderer* Renderer);
};