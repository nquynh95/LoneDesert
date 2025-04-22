#include <iostream>
#include "global.h"
#include "graphics.h"
#include "intro.h"
#include "menu.h"
#include "play.h"
#include "gameover.h"

using namespace std;

int main(int argc, char* args[]){
    if (!init()) return -1;
    loadAssets();
    if (!roadTexture || !carTextures[0]) return -1;

    bool quit = false;
    SDL_Event e;

    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT) quit = true;

            if (gameState == INTRO) eIntro(e);
            else if (gameState == MENU) eMenu(e);
            else if (gameState == PLAYING) ePlay(e);
        }

        if (gameState == INTRO){
            renderIntro();
            continue;
        }

        if (gameState == MENU){
            renderMenu();
            continue;
        }

        carRect.x += carVelX;
        if (carRect.x < 120) carRect.x = 120;
        if (carRect.x + carRect.w > 490) carRect.x = 490 - carRect.w;

        backgroundY += SCROLL_SPEED;
        if (backgroundY >= SCREEN_HEIGHT) backgroundY = 0;

        updateObs();
        updateBush();

        bool hit = false;
        for (int i = 0; i < MAX_OBS; i++)
            if (checkCollision(carRect, obs[i])) hit = true;

        if (hit || (bushActive && checkCollision(carRect, bushRect))){
            renderGameOver();
            eGameOver(quit,e);
        }

        totalDistance++;
        renderGame();
        SDL_Delay(16);
    }

    close();
    return 0;
}
