#ifndef GLOBAL_H
#define GLOBAL_H

#include <SDL.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Texture* introTexture;
extern SDL_Texture* menuTexture;
extern SDL_Texture* re_hoTexture;

enum GameState {INTRO, MENU, PLAYING};
extern GameState gameState;

extern SDL_Texture* roadTexture;
extern int road;

const int SCROLL_SPEED = 5; //tốc độ cuộn
extern int totalDistance;

//xe chọn trong menu
const int NUM_CARS = 4;
extern SDL_Texture* carTextures[NUM_CARS];
extern SDL_Rect carRects[NUM_CARS];
extern int selectedCar;

//xe chơi
extern SDL_Texture* carTexture;
extern SDL_Rect carRect;
const int CAR_SPEED = 10;
extern int carVel;

//đá
extern SDL_Texture* obsTexture;
const int MAX_OBS = 3;
extern SDL_Rect obs[MAX_OBS];
const int OBS_SPEED = 5;

//bụi gai
extern SDL_Texture* bushTexture;
extern SDL_Rect bushRect;
extern bool bushActive;
extern bool bushMoving;
extern int bushSpeed;
extern int bushCooldown;

extern TTF_Font* font;

extern SDL_Rect playRect;
extern SDL_Rect startRect;
extern SDL_Rect restartRect;
extern SDL_Rect homeRect;

#endif // GLOBAL_H

