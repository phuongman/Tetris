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
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    
    Game game("Tetris");
    Mix_PlayChannel(-1, game.music[BACKGROUND_MUSIC], -1); 
    Uint32 start = SDL_GetTicks();
    while(game.running())
    {
        game.clear();
        if(game.status == GAME_PRE_PLAY)
        {
            game.board.resetBoard();
            game.renderView();
            game.handleEventInView();
            game.prev_time = SDL_GetTicks();
        }
        else{
            game.renderBackground();
            game.handleStatus();
            Uint32 time = SDL_GetTicks() - start;
            if (time < FPS_time) {
                SDL_Delay(FPS_time - time);
            }
        }
        game.display();
        
    }
    return 0;
}