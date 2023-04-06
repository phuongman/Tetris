#include "header/block.hpp"

// khởi tạo một khối block
Block::Block()
{
    this->curr_block = rand() % 7;
    this->type_brick = 1 + rand() % 5;
    int mark = 0, count = 1;;
    int length = LENGTH_BLOCK[this->curr_block];
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
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

// hàm xoay block
void Block::rotate()
{
    int temp_matrix[4][4];
    int length = LENGTH_BLOCK[this->curr_block];
    for(int i = 0; i < length; i++)
    for(int j = 0; j < length; j++) temp_matrix[i][j] = this->matrix[i][j];
    
    for(int i = 0; i < length; i++)
    for(int j = 0; j < length; j++) this->matrix[i][j] = temp_matrix[j][length - i - 1];
}

// update tọa độ của các ô brick trong bảng chơi
void Block::updateXY(int x, int y)
{
    int length = LENGTH_BLOCK[this->curr_block];
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++) 
        {
            this->xy[i][j] = {x + j, y + i};
        }
    }
}

