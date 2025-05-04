#include "menu.h"
#include "global.h"
#include "graphics.h"
#include "play.h"

void eMenu(SDL_Event& e){
    if (e.type == SDL_MOUSEBUTTONDOWN){
        int x = e.button.x, y = e.button.y;
        //chọn xe
        for (int i = 0; i < NUM_CARS; i++){
            if (x >= carRects[i].x && x <= carRects[i].x + carRects[i].w &&
                y >= carRects[i].y && y <= carRects[i].y + carRects[i].h){
                selectedCar = i;
            }
        }
        //nhấn start để play
        if (x >= startRect.x && x <= startRect.x + startRect.w &&
            y >= startRect.y && y <= startRect.y + startRect.h){
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
        //viền xe chọn
        if (i == selectedCar){
            SDL_RenderDrawRect(renderer, &carRects[i]);
        }
    }
    SDL_RenderPresent(renderer);
}

