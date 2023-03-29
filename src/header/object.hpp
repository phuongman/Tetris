#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
using namespace std;

class Object
{
public:
    int x, y, w, h;
    SDL_Rect src, dst;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    TTF_Font* font = NULL;
    bool render = false;

    Object();
    void setDst(SDL_Rect dst);
    void setRenderer(SDL_Renderer* renderer);
    void setFont(TTF_Font* font);
    void loadTexture(const char* path);
    void loadFromeRenderText(string textureText, SDL_Color textColor);
    void draw();
private:

};
