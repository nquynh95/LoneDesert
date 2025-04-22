#include "menu.h"
#include "global.h"
#include "graphics.h"
#include "play.h"

void eMenu(SDL_Event& e){
    if (e.type == SDL_MOUSEBUTTONDOWN){
        int x = e.button.x, y = e.button.y;
        for (int i = 0; i < NUM_CARS; i++){
            if (x >= carRects[i].x && x <= carRects[i].x + carRects[i].w &&
                y >= carRects[i].y && y <= carRects[i].y + carRects[i].h){
                selectedCar = i;
            }
        }
        if (x >= playButtonRect.x && x <= playButtonRect.x + playButtonRect.w &&
            y >= playButtonRect.y && y <= playButtonRect.y + playButtonRect.h){
            carTexture = carTextures[selectedCar];
            restartGame();
            gameState = PLAYING;
        }
    }
}

void renderMenu(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
    for (int i = 0; i < NUM_CARS; i++){
        SDL_RenderCopy(renderer, carTextures[i], NULL, &carRects[i]);
        if (i == selectedCar){
            SDL_RenderDrawRect(renderer, &carRects[i]);
        }
    }
    SDL_Texture* playButtonTexture = renderText("START", textColor);
    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
    SDL_RenderPresent(renderer);
}

