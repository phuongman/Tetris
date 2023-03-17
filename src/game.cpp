#include "header/game.hpp"

Game::Game(const char* title)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        cout << "Can't not create a window" << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        cout << "Can't not create a renderer" << endl;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    Game::configResource();
}

void Game::configResource()
{
    board.Init(renderer);

    arr_object[BACKGROUND].setRenderer(renderer);
    arr_object[CAT].setRenderer(renderer);
    arr_object[BOARD].setRenderer(renderer);
    arr_object[BRICK].setRenderer(renderer);
    

    arr_object[BACKGROUND].loadTexture("image/background.png");
    arr_object[CAT].loadTexture("image/cat.png");
    arr_object[BOARD].loadTexture("image/board.png");
    arr_object[BRICK].loadTexture("image/brick.png");

    arr_object[BACKGROUND].setDst({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT});
    int length = 300;
    arr_object[CAT].setDst({SCREEN_WIDTH - length, SCREEN_HEIGHT - length, length, length});    
    arr_object[BOARD].setDst({XPOS, YPOS, 350, 700});
    arr_object[BRICK].setDst({0, 0, LENGTH_SQUARE, LENGTH_SQUARE});




}
bool Game::running()
{
    return is_running;
}

void Game::clear()
{
    SDL_RenderClear(renderer);
}

void Game::renderBackground()
{   
    arr_object[BACKGROUND].draw();
    arr_object[CAT].draw();
    arr_object[BOARD].draw();
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            arr_object[BRICK].dst.x = arr_object[BOARD].dst.x + i * LENGTH_SQUARE;
            arr_object[BRICK].dst.y = arr_object[BOARD].dst.y + j * LENGTH_SQUARE;
            arr_object[BRICK].draw();
            
        }
    }
}
void Game::display()
{
    SDL_RenderPresent(renderer);
}

void Game::handleStatus()
{
    int x = DIS_X, y = 0;
    while(x < 10 && x >= 0 && y < 20 && y >= 0 && is_running){
        Game::clear();
        Game::renderBackground();
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT) {is_running = false; continue;}
        if(e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_DOWN:
                y++;
                break;
            case SDLK_LEFT:
                x--;
                break;
            case SDLK_RIGHT:
                x++;
                break;
            case SDLK_UP:
                board.block.rotate();
                break;
            default:
                break;
            }    
        }
        if (x < 10 && x >= 0 && y < 20 && y >= 0) board.showBlock(x, y);
        Game::display();
    }
    // board.showBlock(DIS_X, 0);
    // Game::display();
}