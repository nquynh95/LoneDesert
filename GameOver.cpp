#include "gameover.h"
#include "global.h"
#include "graphics.h"
#include "play.h"

void renderGameOver(){
    SDL_Texture* gameOverText = renderText("Game Over", textColor);
    SDL_Rect textRect = {SCREEN_WIDTH/2 - 200, SCREEN_HEIGHT/2 - 50, 400, 100};
    SDL_RenderCopy(renderer, gameOverText, NULL, &textRect);
    restartButtonTexture = renderText("RESTART", {255, 255, 255, 255});
    SDL_RenderCopy(renderer, restartButtonTexture, NULL, &restartButtonRect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(gameOverText);
}

void eGameOver(bool& quit, SDL_Event& e){
    bool wait = true;
    while (wait){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
                wait = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN){
                int x = e.button.x;
                int y = e.button.y;
                if (x >= restartButtonRect.x && x <= restartButtonRect.x + restartButtonRect.w &&
                    y >= restartButtonRect.y && y <= restartButtonRect.y + restartButtonRect.h){
                    restartGame();
                    wait = false;
                }
            }
        }
    }
}

