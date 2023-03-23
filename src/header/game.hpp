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
    int status = GAME_PLAYING;

    Object arr_object[NEW_ELEMENT_OBJECT];
    Object game_over;
    Board board;
    Uint32 prev_time = 0;
    Uint32 curr_time = 0;
    Game(const char* title);
    void configResource();
    bool running();
    void clear();
    void renderBackground();
    void handleEvent();
    void display();
    void keyPresses();
    void downBlock();
    int checkGameOver();
    void handleStatus();
    void updateB();
private:
    bool is_running = true;
};