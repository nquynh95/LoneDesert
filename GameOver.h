#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <SDL.h>

using namespace std;

void gameOver(bool& quit, SDL_Event& e);
void eGameOver(bool& quit, SDL_Event& e);
void renderGameOver();

#endif // GAME_OVER_H

