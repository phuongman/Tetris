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
    SDL_Point point[ROW][COLUM] = {{0}};
    Object brick[6];
    Block block;
    int x = DIS_X, y = 0;
    Board();
    void Init(SDL_Renderer* renderer);
    bool checkBorder(int x, int y);
    bool checkRotate(int x, int y);
    void showBlock();
    void render();
private:


};