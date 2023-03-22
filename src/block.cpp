#include "header/block.hpp"
Block::Block()
{
    this->curr_block = rand() % 7;
    this->type_brick = 1 + rand() % 5;
    int mark = 0, count = 1;;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(TYPE_BLOCK[curr_block][mark] == count) 
            {
                this->matrix[i][j] = 1;
                mark++;
            }
            else this->matrix[i][j] = 0;
            count++;
        }
    }

//     // toa do x, y, render ban dau cua o ij trong bang board
    this->updateXY(DIS_X, DIS_Y);
}

void Block::rotate()
{
    int temp_matrix[4][4];
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) temp_matrix[i][j] = this->matrix[i][j];
    
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) this->matrix[i][j] = temp_matrix[j][3 - i];
}

void Block::updateXY(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++) 
        {
            this->xy[i][j] = {x + j, y + i};
        }
    }
}