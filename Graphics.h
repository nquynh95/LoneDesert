#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

bool init();
void loadAssets();
SDL_Texture* loadTexture(const char* path);
SDL_Texture* renderText(const char* text, SDL_Color color);
void close();

#endif // GRAPHICS_H

