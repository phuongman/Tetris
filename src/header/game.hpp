#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
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
    TTF_Font* font = NULL;
    Mix_Chunk* music[NEW_ELEMENT_MUSIC];
    
    SDL_Point mousePoint;

    int status = GAME_PRE_PLAY;
    int mouse_x, mouse_y;
    Uint32 cnt_time = 1000;
    
    

    Object arr_object[NEW_ELEMENT_OBJECT];
    Object game_over;
    Object score;
    Object line;
    Object home, home_light;
    Object arr_view[NEW_ELEMENT_VIEW], hello;
    
    Board board;
    Uint32 prev_time = 0;
    Uint32 curr_time = 0;
    Uint32 cnt_line = 0;
    Uint32 cnt_score = 0;

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
    void updateLine(int val);
    void updateScore(int val);
    void showLine();
    void showScore();
    void showScoreGameOver();
    void getMousePoint();
    void updateButtonDraw(const int var1, const int var2);
    void updateRenderButton(const int var1, const int var2);
    void renderView();
    void handleEventInView();
private:
    bool is_running = true;
};