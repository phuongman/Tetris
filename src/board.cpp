#include "header/board.hpp"

Board::Board()
{

}
void Board::Init(SDL_Renderer* renderer)
{
    // load brick
    this->renderer = renderer;
    for(int i = 0; i < 6; i++) brick[i].setRenderer(renderer);
    this->brick[0].loadTexture("image/brick0.png");
    this->brick[1].loadTexture("image/brick1.png");
    this->brick[2].loadTexture("image/brick2.png");
    this->brick[3].loadTexture("image/brick3.png");
    this->brick[4].loadTexture("image/brick4.png");
    this->brick[5].loadTexture("image/brick5.png");
    for(int i = 0; i < 6; i++) this->brick[i].setDst({0, 0, LENGTH_SQUARE, LENGTH_SQUARE});

    //toa do render cua o ij trong bang board
    for(int i = 1; i <= 20; i++)
    for(int j = 1; j <= 10; j++) this->point[i][j] = {XPOS + (i - 1) * LENGTH_SQUARE, YPOS + (j - 1) * LENGTH_SQUARE};

    for(int i = 1; i <= 20; i++)
    for(int j = 1; j <= 10; j++) this->board[i][j] = 0;
    for(int i = 0; i <= 21; i++) this->board[i][0] = this->board[i][11] = -1;
    for(int i = 0; i <= 10; i++) this->board[0][i] = this->board[21][i] = -1;
}

bool Board::checkBorder(int x, int y)
{
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) 
    if(block.matrix[i][j])
    {
        if(x + j > 10 || x + j < 1 || y + i > 20) return false;
    }
    return true;
}

bool Board::checkRotate(int x, int y)
{
    int tempMatrix[4][4];
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) {
        tempMatrix[i][j] = this->block.matrix[j][3 - i];
        if(tempMatrix[i][j])
        {
            if(x + j > 10 || x + j < 1 || y + i > 20) return false;
        }
    }
    return true;
    
}
void Board::showBlock()
{
    this->block.xpos = XPOS + (this->x - 1) * LENGTH_SQUARE;
    this->block.ypos = YPOS + (this->y - 1) * LENGTH_SQUARE;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(this->block.matrix[i][j])
            {
                this->brick[block.type_brick].dst.x = this->block.xpos + j * LENGTH_SQUARE;
                this->brick[block.type_brick].dst.y = this->block.ypos + i * LENGTH_SQUARE;
                this->brick[block.type_brick].draw();
            }
        }
    }

}
