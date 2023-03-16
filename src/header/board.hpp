#pragma once
#include <iostream>
#include "common.hpp"
#include "block.hpp"
#include "object.hpp"
class Board
{
public:
    SDL_Renderer* renderer = NULL;
    int board[ROW][COLUM] = {{0}};
    Object brick[6];
    Block block;
    Board();
    void Init(SDL_Renderer* renderer);
    void showBlock(int x, int y);
    void render();
private:


};