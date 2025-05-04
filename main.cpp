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
        updateGame();
        gameOver(quit, e);
        renderGame();
        SDL_Delay(20);
    }
    close();
    return 0;
}
