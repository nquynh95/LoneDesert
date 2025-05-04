#include "global.h"
#include "graphics.h"

using namespace std;

bool init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    window = SDL_CreateWindow("Lone Desert", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) return false;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;
    if (TTF_Init() == -1) return false;
    font = TTF_OpenFont("Tektur.ttf", 48);
    if (!font) return false;
    return true;
}

void loadAssets(){
    introTexture = loadTexture("Intro.png");
    menuTexture = loadTexture ("Menu.png");
    roadTexture = loadTexture("road.png");
    obsTexture = loadTexture("obs.png");
    bushTexture = loadTexture("bush.png");
    re_hoTexture = loadTexture("Re_Ho.png");

    for (int i = 0; i < NUM_CARS;i++){
        string path = "car" + to_string(i + 1) + ".png";
        carTextures[i] = loadTexture(path.c_str());
        carRects[i] = {100 + i * 110, 300, 100, 90};
    }
}

SDL_Texture* loadTexture(const char* path){
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (!loadedSurface) return NULL;
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

SDL_Texture* renderText(const char* text, SDL_Color color){
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void close(){
    for (int i = 0; i < NUM_CARS; i++) SDL_DestroyTexture(carTextures[i]);
    SDL_DestroyTexture(roadTexture);
    SDL_DestroyTexture(obsTexture);
    SDL_DestroyTexture(bushTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

