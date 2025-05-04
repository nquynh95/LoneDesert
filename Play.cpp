#include "play.h"
#include "global.h"
#include "graphics.h"

using namespace std;

void ePlay(SDL_Event& e){
    //điều khiển
    if (e.type == SDL_KEYDOWN){
        if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a) carVel = -CAR_SPEED;
        if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d) carVel = CAR_SPEED;
    } else if (e.type == SDL_KEYUP){
        if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT ||
            e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_d)
            carVel = 0;
    }
}

void updateCar(){
    carRect.x += carVel;
    //giới hạn xe
    if (carRect.x < 120) carRect.x = 120;
    if (carRect.x + carRect.w > 490) carRect.x = 490 - carRect.w;
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
        //hiện ngẫu nhiên ở ngoài màn hình
        bushRect.y = rand() % (SCREEN_HEIGHT - 200);
        bushMoving = rand() % 2;
        bushRect.x = bushMoving ? -bushRect.w : SCREEN_WIDTH;
        bushCooldown = 300 + rand() % 500;
    }
    if (bushActive){
        //đi xiên
        bushRect.x += bushMoving ? bushSpeed : -bushSpeed;
        bushRect.y += 4;
        //reset khi ra khỏi màn hình
        if (bushRect.x < -bushRect.w || bushRect.x > SCREEN_WIDTH || bushRect.y > SCREEN_HEIGHT){
            bushActive = false;
            bushCooldown = 300 + rand() % 500;
            bushRect.y = rand() % (SCREEN_HEIGHT / 2);
        }
    } else {
        bushCooldown--;
    }
}

void updateGame(){
    //cuộn đường
    road += SCROLL_SPEED;
    if (road >= SCREEN_HEIGHT) road = 0;
    updateCar();
    updateObs();
    updateBush();
    totalDistance++;
}

void renderGame(){
    SDL_RenderClear(renderer);
    //cuộn đường
    SDL_Rect road1 = {0, road, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect road2 = {0, road - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, roadTexture, NULL, &road1);
    SDL_RenderCopy(renderer, roadTexture, NULL, &road2);

    for (int i = 0; i < MAX_OBS; i++)
        SDL_RenderCopy(renderer, obsTexture, NULL, &obs[i]);

    SDL_RenderCopy(renderer, carTexture, NULL, &carRect);

    if (bushActive){
        static double angle = 0;
        angle += 10; //xoay
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
    carRect.x = 250;
    totalDistance = 0;
    bushActive = false;
    bushCooldown = 0;
    //khởi tạo lại đá
    for (int i = 0; i < MAX_OBS; i++){
        obs[i] = {120 + rand() % (490 - 120 - 50), -100 - i * 250, 50, 50};
    }
}

//check va chạm
bool checkCollision(SDL_Rect a, SDL_Rect b){
    return (a.x + a.w > b.x && a.x < b.x + b.w &&
            a.y + a.h > b.y && a.y < b.y + b.h);
}

bool checkGame(){
    //check xem có va chạm với đá
    for (int i = 0; i < MAX_OBS; i++)
        if (checkCollision(carRect, obs[i])) return true;
    //check va chạm với bụi gai
    if (bushActive && checkCollision(carRect, bushRect)) return true;
    return false;
}
