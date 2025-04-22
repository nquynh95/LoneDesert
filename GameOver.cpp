#include "gameover.h"
#include "global.h"
#include "graphics.h"
#include "play.h"

void renderGameOver(){
    SDL_Texture* gameOverText = renderText("Game Over", {255, 0, 0, 255});
    SDL_Rect textRect = {SCREEN_WIDTH/2 - 200, 200, 400, 100};
    SDL_RenderCopy(renderer, gameOverText, NULL, &textRect);
    SDL_DestroyTexture(gameOverText);

    string score = "Score: " + to_string(totalDistance);
    SDL_Texture* scoreText = renderText(score.c_str(), textColor);
    SDL_Rect scoreRect = {SCREEN_WIDTH/2 - 150, 300, 300, 50};
    SDL_RenderCopy(renderer, scoreText, NULL, &scoreRect);
    SDL_DestroyTexture(scoreText);

    restartButtonTexture = renderText("RESTART", textColor);
    SDL_RenderCopy(renderer, restartButtonTexture, NULL, &restartButtonRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &restartButtonRect);

    homeButtonTexture = renderText("HOME", textColor);
    SDL_RenderCopy(renderer, homeButtonTexture, NULL, &homeButtonRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &homeButtonRect);

    SDL_RenderPresent(renderer);
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
                else if (x >= homeButtonRect.x && x <= homeButtonRect.x + homeButtonRect.w &&
                    y >= homeButtonRect.y && y <= homeButtonRect.y + homeButtonRect.h) {
                    gameState = INTRO;
                    wait = false;
                }
            }
        }
    }
}

