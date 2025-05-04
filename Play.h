#ifndef PLAY_H
#define PLAY_H

#include <SDL.h>
#include <string>

void ePlay(SDL_Event& e);
void updateObs();
void updateBush();
void updateCar();
void updateGame();
void renderGame();
void renderDistance();
void restartGame();
bool checkCollision(SDL_Rect a, SDL_Rect b);
bool checkGame();

#endif // PLAY_H

