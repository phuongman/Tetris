#include "header/board.hpp"

Board::Board()
{

}
void Board::Init(SDL_Renderer* renderer)
{
    // load brick
    this->renderer = renderer;
    for(int i = 0; i < 6; i++) brick[i].setRenderer(renderer);
    brick[0].loadTexture("image/brick0.png");
    brick[1].loadTexture("image/brick1.png");
    brick[2].loadTexture("image/brick2.png");
    brick[3].loadTexture("image/brick3.png");
    brick[4].loadTexture("image/brick4.png");
    brick[5].loadTexture("image/brick5.png");
    for(int i = 0; i < 6; i++) brick[i].setDst({0, 0, LENGTH_SQUARE, LENGTH_SQUARE});
}

void Board::showBlock(int x, int y)
{
    block.xpos = XPOS + x * LENGTH_SQUARE;
    block.ypos = YPOS + y * LENGTH_SQUARE;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(block.matrix[i][j])
            {
                brick[block.type_brick].dst.x = block.xpos + j * LENGTH_SQUARE;
                brick[block.type_brick].dst.y = block.ypos + i * LENGTH_SQUARE;
                brick[block.type_brick].draw();
            }
        }
    }

}
