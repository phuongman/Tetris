#include "header/board.hpp"

Board::Board()
{

}
void Board::Init(SDL_Renderer* renderer)
{
    // load brick
    this->renderer = renderer;
    for(int i = 1; i < 7; i++) brick[i].setRenderer(renderer);
    this->brick[1].loadTexture("image/brick0.png");
    this->brick[2].loadTexture("image/brick1.png");
    this->brick[3].loadTexture("image/brick2.png");
    this->brick[4].loadTexture("image/brick3.png");
    this->brick[5].loadTexture("image/brick4.png");
    this->brick[6].loadTexture("image/brick5.png");
    for(int i = 1; i < 7; i++) this->brick[i].setDst({0, 0, LENGTH_SQUARE, LENGTH_SQUARE});

    //toa do render cua o ij trong bang board
    for(int i = 1; i <= 20; i++)
    for(int j = 1; j <= 10; j++) this->point[i][j] = {XPOS + (j - 1) * LENGTH_SQUARE, YPOS + (i - 1) * LENGTH_SQUARE};

    for(int i = 1; i <= 20; i++)
    for(int j = 1; j <= 10; j++) this->board[i][j] = 0;
    for(int i = 0; i <= 21; i++) this->board[i][0] = this->board[i][11] = -1;
    for(int i = 0; i <= 10; i++) this->board[21][i] = -1;
}

void Board::showBoard()
{
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 10; j++) 
            if(this->board[i][j])
            {
                int type_b = this->board[i][j];
                this->brick[type_b].setDst({this->point[i][j].x, this->point[i][j].y, LENGTH_SQUARE, LENGTH_SQUARE});
                this->brick[type_b].draw();
            }
    }
}
bool Board::checkBorder(int x, int y)
{
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) 
    if(block.matrix[i][j])
    {
        if(y + i > 20) return false;
        if(this->board[y + i - 1][x + j]) return false;
        if(this->board[y + i][x + j]) return false;
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
            if(y + i > 20) return false;
            if(this->board[y + i - 1][x + j]) return false;
            if(this->board[y + i][x + j]) return false;
        }
    }
    return true;
    
}

bool Board::checkCanDown(int x, int y)
{
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
        if(this->block.matrix[i][j])
        {
            if(y + i > 20) return false;
            if(this->board[y + i - 1][x + j]) return false;
            if(this->board[y + i][x + j]) return false;
        }
    return true;
}
void Board::showBlock()
{
    //show brick is running
    // this->block.xpos = XPOS + (this->x - 1) * LENGTH_SQUARE;
    // this->block.ypos = YPOS + (this->y - 1) * LENGTH_SQUARE;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(this->block.matrix[i][j])
            {
                // this->brick[block.type_brick].dst.x = this->block.xpos + j * LENGTH_SQUARE;
                // this->brick[block.type_brick].dst.y = this->block.ypos + i * LENGTH_SQUARE;
                this->brick[block.type_brick].dst.x = XPOS + LENGTH_SQUARE * (this->block.xy[i][j].x - 1);
                this->brick[block.type_brick].dst.y = YPOS + LENGTH_SQUARE * (this->block.xy[i][j].y - 1);
                this->brick[block.type_brick].draw();
            }
        }
    }

    //show border brick
    int y1 = 0;
    for(int t = 1; t <= 20; t++)
        if(this->checkBorder(this->x, t)) y1 = t; else break;
    int xpos1 = XPOS + (this->x - 1) * LENGTH_SQUARE;
    int ypos1 = YPOS + (y1 - 1) * LENGTH_SQUARE;
    if(y1)
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        
            if(this->block.matrix[i][j])
            {
                this->brick[6].dst.x = xpos1 + j * LENGTH_SQUARE;
                this->brick[6].dst.y = ypos1 + i * LENGTH_SQUARE;
                this->brick[6].draw();
            }
    }

    //show next brick

    switch (this->next_block.curr_block)
    {
        case 0:
            xpos1 = SCREEN_WIDTH - 300 + 81;
            ypos1 = YPOS + 35 * 5 - 5;
            break;
        case 1:
            xpos1 = SCREEN_WIDTH - 300 + 79;
            ypos1 = YPOS + 35 * 5 - 5;
            break;
        case 2:
            xpos1 = SCREEN_WIDTH - 220;
            ypos1 = YPOS + 185;
            break;
        case 3:
            xpos1 = SCREEN_WIDTH - 300 + 97;
            ypos1 = YPOS + 35 * 5.4;
            break;
        case 4:
            xpos1 = SCREEN_WIDTH - 300 + 62;
            ypos1 = YPOS + 35 * 5.4;
            break;
        case 5:
            xpos1 = SCREEN_WIDTH - 300 + 81;
            ypos1 = YPOS + 35 * 5 - 5;
            break;
        case 6:
            xpos1 = SCREEN_WIDTH - 300 + 100;
            ypos1 = YPOS + 35 * 4.4;
            break;
        default:
            break;
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(this->next_block.matrix[i][j])
            {
                this->brick[this->next_block.type_brick].dst.x = xpos1 + j * LENGTH_SQUARE;
                this->brick[this->next_block.type_brick].dst.y = ypos1 + i * LENGTH_SQUARE;
                this->brick[this->next_block.type_brick].draw();
            }
        }
    }


}

void Board::updateBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(this->block.matrix[i][j])
            {
                int _x = this->block.xy[i][j].x;
                int _y = this->block.xy[i][j].y;
                this->board[_y][_x] = this->block.type_brick;
            }
        }
    }

}
int Board::checkCreateRow()
{   
    int cnt = 0;
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j < 11; j++) 
        {
            if(!this->board[i][j]) 
            {
                this->deleteRow(cnt, i - 1);
                cnt = -1;
                break;
            }
        }
        cnt++;
    }
    this->deleteRow(cnt, 20);
    return cnt;
}
void Board::deleteRow(int cnt, int xpos)
{   
    for(int i = xpos; i > 0; i--)
    for(int j = 1; j < 11; j++)
    {
        this->board[i][j] = this->board[max(0, i - cnt)][j];
    }
}