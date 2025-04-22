#include "play.h"
#include "global.h"
#include "graphics.h"

using namespace std;

void ePlay(SDL_Event& e){
    if (e.type == SDL_KEYDOWN){
        if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a) carVelX = -CAR_SPEED;
        if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d) carVelX = CAR_SPEED;
    } else if (e.type == SDL_KEYUP){
        if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT ||
            e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_d)
            carVelX = 0;
    }
}

bool checkCollision(SDL_Rect a, SDL_Rect b){
    return (a.x + a.w > b.x && a.x < b.x + b.w &&
            a.y + a.h > b.y && a.y < b.y + b.h);
}
void renderGame(){
    SDL_RenderClear(renderer);
    SDL_Rect bg1 = {0, backgroundY, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect bg2 = {0, backgroundY - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, roadTexture, NULL, &bg1);
    SDL_RenderCopy(renderer, roadTexture, NULL, &bg2);

    for (int i = 0; i < MAX_OBS; i++)
        SDL_RenderCopy(renderer, obsTexture, NULL, &obs[i]);

    SDL_RenderCopy(renderer, carTexture, NULL, &carRect);

    if (bushActive){
        static double angle = 0;
        angle += 10;
        SDL_Point center = { bushRect.w/2, bushRect.h/2 };
        SDL_RenderCopyEx(renderer, bushTexture, NULL, &bushRect, angle, &center, SDL_FLIP_NONE);
    }

    renderDistance();
    SDL_RenderPresent(renderer);
}

void renderDistance(){
    string text = "Distance: " + to_string(totalDistance) + " m";
    SDL_Texture* distanceText = renderText(text.c_str(), {255, 255, 255, 255});
    SDL_Rect textRect = {10, 10, 200, 50};
    SDL_RenderCopy(renderer, distanceText, NULL, &textRect);
    SDL_DestroyTexture(distanceText);
}


void restartGame(){
    carRect.x = SCREEN_WIDTH/2 - 50;
    totalDistance = 0;
    bushActive = false;
    bushRect.x = -100;
    bushCooldown = 0;
    for (int i = 0; i < MAX_OBS; i++){
        obs[i] = {120 + rand() % (490 - 120 - 50), -100 - i * 200, 50, 50};
    }
}
void updateObs(){
    for (int i = 0; i < MAX_OBS; i++){
        obs[i].y += OBS_SPEED;
        if (obs[i].y > SCREEN_HEIGHT){
            obs[i].y = -100;
            obs[i].x = 120 + rand() % (490 - 120 - obs[i].w);
        }
    }
}

void updateBush(){
    if (!bushActive && bushCooldown <= 0){
        bushActive = true;
        bushRect.w = 60;
        bushRect.h = 60;
        bushRect.y = rand() % (SCREEN_HEIGHT - 200);
        bushMovingRight = rand() % 2;
        bushRect.x = bushMovingRight ? -bushRect.w : SCREEN_WIDTH;
        bushCooldown = 300 + rand() % 500;
    }
    if (bushActive){
        bushRect.x += bushMovingRight ? bushSpeed : -bushSpeed;
        bushRect.y += 4;
        if (bushRect.x < -bushRect.w || bushRect.x > SCREEN_WIDTH || bushRect.y > SCREEN_HEIGHT){
            bushActive = false;
            bushCooldown = 300 + rand() % 500;
            bushRect.y = rand() % (SCREEN_HEIGHT / 2);
        }
    } else {
        bushCooldown--;
    }
}

