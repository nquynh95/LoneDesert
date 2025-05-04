#include "global.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* roadTexture = NULL;
SDL_Texture* introTexture = NULL;
SDL_Texture* menuTexture = NULL;
SDL_Texture* re_hoTexture = NULL;

GameState gameState = INTRO;

int road = 0;
int totalDistance = 0;

SDL_Texture* carTextures[NUM_CARS];
SDL_Rect carRects[NUM_CARS];
int selectedCar = 0;

SDL_Texture* carTexture = NULL;
SDL_Rect carRect = {250, 600, 110, 100};
int carVel = 0;

SDL_Texture* obsTexture = NULL;
SDL_Rect obs[MAX_OBS];

SDL_Texture* bushTexture = NULL;
SDL_Rect bushRect = {-100, 150, 50, 50};
bool bushActive = false;
bool bushMoving = true;
int bushSpeed = 4;
int bushCooldown = 0;

TTF_Font* font = NULL;

SDL_Rect playRect = {150, 500, 300, 60};
SDL_Rect startRect = {225, 550, 150, 80};
SDL_Rect restartRect = {185, 400, 240, 80};
SDL_Rect homeRect = {185, 500, 240, 80};
