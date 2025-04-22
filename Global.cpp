#include "global.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* roadTexture = NULL;
SDL_Texture* introTexture = NULL;
SDL_Texture* menuTexture = NULL;

GameState gameState = INTRO;

int backgroundY = 0;
int totalDistance = 0;

SDL_Texture* carTextures[NUM_CARS];
SDL_Rect carRects[NUM_CARS];
int selectedCar = 0;

SDL_Texture* carTexture = NULL;
SDL_Rect carRect = {SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT -200, 110, 100};
int carVelX = 0;

SDL_Texture* obsTexture = NULL;
SDL_Rect obs[MAX_OBS];

SDL_Texture* bushTexture = NULL;
SDL_Rect bushRect = {-100, SCREEN_HEIGHT -250, 50, 50};
bool bushActive = false;
bool bushMovingRight = true;
int bushSpeed = 4;
int bushCooldown = 0;

TTF_Font* font = NULL;
SDL_Color textColor = {255, 255, 255, 255};

SDL_Texture* playButtonTexture = NULL;
SDL_Rect playButtonRect = {SCREEN_WIDTH/2 - 75, 550, 150, 80};

SDL_Rect restartButtonRect = {SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 + 80, 200, 60};
SDL_Texture* restartButtonTexture = NULL;

SDL_Rect homeButtonRect = {SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT / 2 + 160, 200, 60};
SDL_Texture* homeButtonTexture = NULL;
