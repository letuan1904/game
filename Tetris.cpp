#include "Board.h"
#include "Tetromino.h"
#include "Texture.h"
#include "Constants.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <time.h>

Board board;
SDL_Window* Window = NULL;
SDL_Renderer* Renderer = NULL;
Texture background, tScore, score, tLine, line, tBest, best, menu;
Texture gameOver;
Texture tNext;
TTF_Font *font = NULL, *eFont = NULL;

bool start = false;
bool PLAY = true;
bool EXIT = false;
bool isRunning = true;


bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Cant initialize" << std::endl;
		return false;
	}
	else {
		Window = SDL_CreateWindow("Tetris Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
		if (TTF_Init() == -1)
		{
			std::cout << "SDL_ttf could not initialize! SDL_ttf Error:" << TTF_GetError() << std::endl;
			return false;
		}
	}

	return true;
}
void close() {
	//free textures
	background.free();
	tScore.free();
	score.free();
	tLine.free();
	line.free();
	tBest.free();
	best.free();
	menu.free();
	gameOver.free();
	//end game
	isRunning = false;
	//close font
	TTF_CloseFont(font);
	font = NULL;
	eFont = NULL;
	//free renderer and window
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;
	//quit all
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Tetromino tetromino((1 + rand() % NUMBER_OF_TYPES));
	Tetromino nextTetromino((1 + rand() % NUMBER_OF_TYPES));
	if (init()) {
		//load font
		font = TTF_OpenFont("Stock/font.ttf", 40);
		eFont = TTF_OpenFont("Stock/silkscreen1.ttf", 80);
		//load background
		background.loadFromFile(Renderer, "Stock/bg4.png");
		//load the screen before starting the game
		menu.loadFromFile(Renderer, "Stock/MENU.png");

		//load text
		SDL_Color textColor{ 255,255,255,255 };
		tScore.loadFromRenderedText(Renderer, font, "SCORE", textColor);
		tLine.loadFromRenderedText(Renderer, font, "LINE", textColor);
		tBest.loadFromRenderedText(Renderer, font, "BEST", textColor);
		tNext.loadFromRenderedText(Renderer, font, "NEXT", textColor);
		SDL_Color endColor{ 228,41,27,255 };
		gameOver.loadFromRenderedText(Renderer, eFont, "GAME OVER", endColor);

		uint32_t moveTime;

		while (isRunning) {
			//working with main MENU
			if (!start) {
				menu.render(Renderer, 0, 0, NULL, true);
				SDL_Event e;
				if (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_KEYDOWN) {
						switch (e.key.keysym.sym) {
						case SDLK_SPACE:
						case SDLK_RETURN:
							if (PLAY) {
								start = true;
								board = Board(board.getHighScore());
								moveTime = SDL_GetTicks();
							}
							else
								if (EXIT) {
									close();
								}
							break;
						case SDLK_DOWN:
						case SDLK_UP:
							PLAY = !PLAY;
							EXIT = !EXIT;
							break;
						}
					}
					else
						if (e.type == SDL_QUIT)
							close();
				}
				SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
				if (PLAY) {
					SDL_Rect rect{ 210,180,300,65 };
					SDL_RenderDrawRect(Renderer, &rect);
				}
				else
					if (EXIT) {
						SDL_Rect rect{ 210,275,300,65 };
						SDL_RenderDrawRect(Renderer, &rect);
					}
			}
			//working with the game
			else {
				SDL_Event e;
				if (SDL_PollEvent(&e) != 0)
				{
					switch (e.type)
					{
					case SDL_KEYDOWN:
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_DOWN:
						{
							Tetromino temp = tetromino;
							temp.move(0, 1);
							if (!board.isCollision(temp))
								tetromino = temp;
						}
						break;
						case SDLK_RIGHT:
						{
							Tetromino temp = tetromino;
							temp.move(1, 0);
							if (!board.isCollision(temp))
								tetromino = temp;
						}
						break;
						case SDLK_LEFT:
						{
							Tetromino temp = tetromino;
							temp.move(-1, 0);
							if (!board.isCollision(temp))
								tetromino = temp;
						}
						break;
						case SDLK_UP:
						{
							Tetromino temp = tetromino;
							temp.rotate();
							if (!board.isCollision(temp))
								tetromino = temp;
						}
						break;
						}
					}
					break;
					case SDL_QUIT:
						close();
						break;
					}
				}
				//clear the screen
				SDL_SetRenderDrawColor(Renderer, 30, 30, 30, 0xff);
				SDL_RenderClear(Renderer);

				//render background
				background.render(Renderer, 0, 0, NULL, true);

				//render text LINE SCORE BEST to the screen
				tLine.render(Renderer, SCREEN_WIDTH / 2, 7 * SCREEN_HEIGHT / 10 - 140);
				tScore.render(Renderer, SCREEN_WIDTH / 2, 7 * SCREEN_HEIGHT / 10 - 0);
				tBest.render(Renderer, SCREEN_WIDTH / 2, 7 * SCREEN_HEIGHT / 10 + 140);
				tNext.render(Renderer, SCREEN_WIDTH - 240, 50);

				//update and render line, score, best score
				SDL_Color scoreColor{ 113,227,193,0 };

				line.loadFromRenderedText(Renderer, font, std::to_string(board.getLines()), scoreColor);
				line.render(Renderer, SCREEN_WIDTH - 90, 7 * SCREEN_HEIGHT / 10 - 140);

				score.loadFromRenderedText(Renderer, font, std::to_string(board.getScore()), scoreColor);
				score.render(Renderer, SCREEN_WIDTH - 90, 7 * SCREEN_HEIGHT / 10 - 0);

				SDL_Color highScoreColor{ 255,10,10,0 };

				best.loadFromRenderedText(Renderer, font, std::to_string(board.getHighScore()), highScoreColor);
				best.render(Renderer, SCREEN_WIDTH - 90, 7 * SCREEN_HEIGHT / 10 + 140);

				//load the respective color of each block
				tetromino.getBlockColor(Renderer);
				board.block.loadBlocks(Renderer);

				//draw board and tetro
				board.draw(Renderer);
				tetromino.draw(Renderer);

				//check time to move the tetromino
				if (SDL_GetTicks() > moveTime)
				{
					moveTime += board.delayTime();
					//move down
					Tetromino temp = tetromino;
					temp.move(0, 1);

					if (board.isCollision(temp))
					{
						board.deleteLines(tetromino);
						//create new tetromino
						tetromino = nextTetromino;
						nextTetromino = Tetromino{ (1 + rand() % NUMBER_OF_TYPES) };
						//if the new one cant be created it means the game is over :((
						if (board.isCollision(tetromino))
						{
							while (start) {
								SDL_Rect rect{ 100,180,520,360 };
								SDL_SetRenderDrawColor(Renderer, 96, 89, 117, 255);
								SDL_RenderFillRect(Renderer, &rect);
								SDL_RenderDrawRect(Renderer, &rect);
								//show the GAME OVER, score and high score
								gameOver.render(Renderer, 115, 220);

								tScore.render(Renderer, 180, 320);
								tBest.render(Renderer, 180 + 260, 320);

								score.render(Renderer, 210, 320 + 100);
								best.render(Renderer, 210 + 260, 320 + 100);

								SDL_RenderPresent(Renderer);
								SDL_Event e;
								if (SDL_PollEvent(&e) != 0) {
									if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
										start = false;
									}
								}
								if (SDL_PollEvent(&e) != 0) {
									if (e.type == SDL_KEYDOWN) {
										switch (e.key.keysym.sym) {
											//back to menu
										case SDLK_SPACE:
										case SDLK_RETURN:
											start = false;
											break;
										}
									}
									else
										if (e.type == SDL_QUIT)
											close();
								}
							}
						}
					}
					else
					{
						tetromino = temp;
					}
				}
				//draw next Tetromino
				board.drawNext(Renderer, nextTetromino);
			}
			SDL_RenderPresent(Renderer);
		}
	}
	close();
	return 0;
}
