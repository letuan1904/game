#include "Block.h"

Block::Block() {
}

Block::~Block() {}

void Block::loadBlocks(SDL_Renderer* Renderer) {
	red.loadFromFile(Renderer, "Stock/red.jpg");
	yellow.loadFromFile(Renderer, "Stock/yellow.jpg");
	skyblue.loadFromFile(Renderer, "Stock/skyblue.jpg");
	blue.loadFromFile(Renderer, "Stock/blue.jpg");
	purple.loadFromFile(Renderer, "Stock/purple.jpg");
	orange.loadFromFile(Renderer, "Stock/orange.jpg");
	green.loadFromFile(Renderer, "Stock/green.jpg");
}