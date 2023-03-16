#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "common.hpp"
#include "object.hpp"
#include "board.hpp"
using namespace std;

class Game
{
public:
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    SDL_Event e;

    Object arr_object[NEW_ELEMENT_OBJECT];
    Board board;
    Game(const char* title);
    void configResource();
    bool running();
    void clear();
    void renderBackground();
    void display();
    void handleStatus();
private:
    bool is_running = true;
};