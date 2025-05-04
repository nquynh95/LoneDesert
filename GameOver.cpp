#include "gameover.h"
#include "global.h"
#include "graphics.h"
#include "play.h"

void gameOver(bool& quit, SDL_Event& e){
    if (checkGame()){
        renderGameOver();
        eGameOver(quit,e);
    }
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
                //nhấn restart để chơi lại
                if (x >= restartRect.x && x <= restartRect.x + restartRect.w &&
                    y >= restartRect.y && y <= restartRect.y + restartRect.h){
                    restartGame();
                    wait = false;
                }
                //nhấn home về intro
                else if (x >= homeRect.x && x <= homeRect.x + homeRect.w &&
                         y >= homeRect.y && y <= homeRect.y + homeRect.h) {
                    gameState = INTRO;
                    wait = false;
                }
            }
        }
    }
}

void renderGameOver(){
    SDL_Texture* gameOverText = renderText("Game Over", {255, 0, 0, 255});
    SDL_Rect textRect = {100, 200, 400, 100};
    SDL_RenderCopy(renderer, gameOverText, NULL, &textRect);
    SDL_DestroyTexture(gameOverText);

    string score = "Score: " + to_string(totalDistance);
    SDL_Texture* scoreText = renderText(score.c_str(), {255, 255, 255, 255});
    SDL_Rect scoreRect = {150, 300, 300, 50};
    SDL_RenderCopy(renderer, scoreText, NULL, &scoreRect);
    SDL_DestroyTexture(scoreText);

    SDL_Rect restart = {1, 2, 240, 80};
    SDL_RenderCopy(renderer, re_hoTexture, &restart, &restartRect);

    SDL_Rect home = {1, 96, 240, 80};
    SDL_RenderCopy(renderer, re_hoTexture, &home, &homeRect);

    SDL_RenderPresent(renderer);
}

