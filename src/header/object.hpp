#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
using namespace std;

class Object
{
public:
    int x, y, w, h;
    SDL_Rect src, dst;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;

    Object();
    void setDst(SDL_Rect dst);
    void setRenderer(SDL_Renderer* renderer);
    void loadTexture(const char* path);
    void draw();
private:

};