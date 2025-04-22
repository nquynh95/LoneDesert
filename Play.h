#ifndef PLAY_H
#define PLAY_H

#include <SDL.h>
#include <string>

void ePlay(SDL_Event& e);
void updateObs();
void updateBush();

void renderGame();
void renderDistance();
void GameOver(bool& quit, SDL_Event& e);

bool checkCollision(SDL_Rect a, SDL_Rect b);

void restartGame();

#endif // PLAY_H

