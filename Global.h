#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* roadTexture;
extern SDL_Texture* introTexture;
extern SDL_Texture* menuTexture;

enum GameState {INTRO, MENU, PLAYING};
extern GameState gameState;

extern int backgroundY;
const int SCROLL_SPEED = 5;
extern int totalDistance;

const int NUM_CARS = 4;
extern SDL_Texture* carTextures[NUM_CARS];
extern SDL_Rect carRects[NUM_CARS];
extern int selectedCar;
extern SDL_Texture* carTexture;
extern SDL_Rect carRect;
const int CAR_SPEED = 10;
extern int carVelX;

extern SDL_Texture* obsTexture;
const int MAX_OBS = 3;
extern SDL_Rect obs[MAX_OBS];
const int OBS_SPEED = 5;

extern SDL_Texture* bushTexture;
extern SDL_Rect bushRect;
extern bool bushActive;
extern bool bushMovingRight;
extern int bushSpeed;
extern int bushCooldown;

extern TTF_Font* font;
extern SDL_Color textColor;

extern SDL_Texture* playButtonTexture;
extern SDL_Rect playButtonRect;

extern SDL_Rect restartButtonRect;
extern SDL_Texture* restartButtonTexture;

extern SDL_Rect homeButtonRect;
extern SDL_Texture* homeButtonTexture;

#endif // GLOBAL_H

