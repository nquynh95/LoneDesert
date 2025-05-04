#include "intro.h"
#include "global.h"
#include "graphics.h"

void eIntro(SDL_Event& e){
    if (e.type == SDL_MOUSEBUTTONDOWN){
        int x = e.button.x, y = e.button.y;
        //nhấn play để vào menu
        if (x >= playRect.x && x <= playRect.x + playRect.w &&
            y >= playRect.y && y <= playRect.y + playRect.h)
            gameState = MENU;
    }
}

void renderIntro(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, introTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

