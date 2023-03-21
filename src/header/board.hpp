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
    
    Object brick[7];
    
    Block block = Block();
    Block next_block = Block();
    bool new_block = false;

    int x = DIS_X, y = DIS_Y;
    
    Board();
    void Init(SDL_Renderer* renderer);
    bool checkBorder(int x, int y);
    bool checkRotate(int x, int y);
    bool checkCanDown(int x, int y);
    void showBoard();
    void updateBoard();
    void downTetris();
    void showBlock();
    void render();
private:


};