#include <iostream>
#include "header/game.hpp"
using namespace std;

int main(int argc, char* args[]) 
{
    srand(time(NULL));
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems Initialized... " << endl;
    }
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    
    Game game("Tetris");
    Uint32 start = SDL_GetTicks();
    game.prev_time = SDL_GetTicks();
    while(game.running())
    {
        game.clear();
        game.renderBackground();
        game.handleStatus();
        game.display();
         Uint32 time = SDL_GetTicks() - start;
        if (time < FPS_time) {
            SDL_Delay(FPS_time - time);
        }
    }
    return 0;
}