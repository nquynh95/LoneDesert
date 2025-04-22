#include "intro.h"
#include "global.h"
#include "graphics.h"

void eIntro(SDL_Event& e){
    if (e.type == SDL_MOUSEBUTTONDOWN) gameState = MENU;
}

void renderIntro(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, introTexture, NULL, NULL);

    SDL_Texture* play = renderText("PLAY", {255, 255, 255, 255});

    SDL_Rect playRect = {SCREEN_WIDTH/2 - 150, 650, 300, 60};

    SDL_RenderCopy(renderer, play, NULL, &playRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(play);
}

