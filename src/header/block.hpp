#pragma once
#include <bits/stdc++.h>
#include "SDL2/SDL.h"
#include "common.hpp"
using namespace std;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

class Block
{
public:
    int matrix[4][4] = {{0}};
    int curr_block = -1;
    int type_brick = -1;
    SDL_Point xy[4][4] = {{0, 0}};
    int xpos = 0, ypos = 0;
    
    Block(); 
    void rotate();
    void updateXY(int x, int y);

private:

};