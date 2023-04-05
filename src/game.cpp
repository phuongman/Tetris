#include "header/game.hpp"

// Khởi tạo mặc định 
//  khởi tạo một window, render, font chữ và load các texture, âm thanh
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

    font = TTF_OpenFont("SDL/font/OpenSans-SemiboldItalic.ttf", 33);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    Game::configResource();
}

// Load các texture, music cần dùng cho game và khởi tạo một bảng 20 * 10
void Game::configResource()
{
    board.Init(renderer);

    arr_object[BACKGROUND].setRenderer(renderer);
    arr_object[CAT].setRenderer(renderer);
    arr_object[BOARD].setRenderer(renderer);
    arr_object[BRICK].setRenderer(renderer);
    arr_object[NEXT].setRenderer(renderer);
    arr_object[SCORE].setRenderer(renderer);
    //arr_object[HOLD].setRenderer(renderer);
    

    arr_object[BACKGROUND].loadTexture("image/background.png");
    arr_object[CAT].loadTexture("image/cat.png");
    arr_object[BOARD].loadTexture("image/board.png");
    arr_object[BRICK].loadTexture("image/brick.png");
    arr_object[NEXT].loadTexture("image/next.png");
    arr_object[SCORE].loadTexture("image/score.png");
    //arr_object[HOLD].loadTexture("image/hold.png");

    arr_object[BACKGROUND].setDst({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT});
    int length = 300;
    arr_object[CAT].setDst({SCREEN_WIDTH - length, SCREEN_HEIGHT - length, length, length});    
    arr_object[BOARD].setDst({XPOS, YPOS, 350, 700});
    arr_object[BRICK].setDst({0, 0, LENGTH_SQUARE, LENGTH_SQUARE});
    //arr_object[HOLD].setDst({50, YPOS, 250, 250});
    arr_object[NEXT].setDst({(SCREEN_WIDTH - 300) + (300 - 250) / 2, YPOS, 250, 400});
    arr_object[SCORE].setDst({50, YPOS, 250, 400});
    //(SCREEN_HEIGHT - YPOS - 400)


    game_over.setRenderer(renderer);
    game_over.loadTexture("image/gameover.png");
    game_over.setDst({(SCREEN_WIDTH - 300) / 2, (SCREEN_HEIGHT - 250) / 2, 300, 250});

    home.setRenderer(renderer);
    home.loadTexture("image/home.png");
    home.setDst({(SCREEN_WIDTH - 60) / 2, this->game_over.dst.y + 250 - 75, 60, 60});
    home.render = true;
    home_light.setRenderer(renderer);
    home_light.loadTexture("image/home_light.png");
    home_light.setDst({(SCREEN_WIDTH - 60) / 2, this->game_over.dst.y + 250 - 75, 60, 60});

    score.setRenderer(renderer);
    line.setRenderer(renderer);

    score.setFont(font);
    line.setFont(font);



// Pre game
    arr_view[BOARD_BACKGROUND].setRenderer(renderer);
    arr_view[PLAY].setRenderer(renderer);
    arr_view[PLAY_LIGHT].setRenderer(renderer);
    arr_view[LEVEL1].setRenderer(renderer);
    arr_view[LEVEL1_LIGHT].setRenderer(renderer);
    arr_view[LEVEL2].setRenderer(renderer);
    arr_view[LEVEL2_LIGHT].setRenderer(renderer);
    arr_view[LEVEL3].setRenderer(renderer);
    arr_view[LEVEL3_LIGHT].setRenderer(renderer);
    arr_view[TETRIS].setRenderer(renderer);

    arr_view[BOARD_BACKGROUND].loadTexture("image/board_background.png");
    arr_view[PLAY].loadTexture("image/play.png");
    arr_view[PLAY_LIGHT].loadTexture("image/play_light.png");
    arr_view[LEVEL1].loadTexture("image/level1.png");
    arr_view[LEVEL1_LIGHT].loadTexture("image/level1_light.png");
    arr_view[LEVEL2].loadTexture("image/level2.png");
    arr_view[LEVEL2_LIGHT].loadTexture("image/level2_light.png");
    arr_view[LEVEL3].loadTexture("image/level3.png");
    arr_view[LEVEL3_LIGHT].loadTexture("image/level3_light.png");
    arr_view[TETRIS].loadTexture("image/tetris.png");

    arr_view[BOARD_BACKGROUND].setDst({(SCREEN_WIDTH - 500) / 2, YPOS, 500, 760});
    arr_view[TETRIS].setDst({(SCREEN_WIDTH - 300) / 2, YPOS + 15, 300, 300});
    arr_view[PLAY].setDst({(SCREEN_WIDTH - 350) / 2, YPOS + 350, 350, 135});
    arr_view[PLAY_LIGHT].setDst(arr_view[PLAY].dst);
    arr_view[LEVEL1].setDst({(SCREEN_WIDTH - 330) / 2, YPOS + 520, 330, 120});
    arr_view[LEVEL1_LIGHT].setDst(arr_view[LEVEL1].dst);
    arr_view[LEVEL2].setDst(arr_view[LEVEL1].dst);
    arr_view[LEVEL2_LIGHT].setDst(arr_view[LEVEL1].dst);
    arr_view[LEVEL3].setDst(arr_view[LEVEL1].dst);
    arr_view[LEVEL3_LIGHT].setDst(arr_view[LEVEL1].dst);
    
    arr_view[LEVEL1].render = true;
    arr_view[PLAY].render = true;

    hello.setRenderer(renderer);
    hello.loadTexture("image/hello.png");
    hello.setDst({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT});

    music[BACKGROUND_MUSIC] = Mix_LoadWAV("music/mix_music.wav");
    music[HELLO_MUSIC] = Mix_LoadWAV("music/hello.wav"); 
    music[GAMEOVER] = Mix_LoadWAV("music/gameover.wav");
    music[MOVE] = Mix_LoadWAV("music/move.wav");
    music[ROTATE] = Mix_LoadWAV("music/rotate.wav");
    music[LINECLEAR] = Mix_LoadWAV("music/lineclear.wav");
    music[CLICK] = Mix_LoadWAV("music/click.wav");
}

// render view trước khi chơi như: background, các nút bấm play, chọn level lên renderer...
void Game::renderView()
{
    arr_object[BACKGROUND].draw();
    arr_object[NEXT].draw();
    arr_object[SCORE].draw();
    arr_view[BOARD_BACKGROUND].draw();
    arr_view[TETRIS].draw();
    arr_view[PLAY].draw();
    if(arr_view[LEVEL1].render) arr_view[LEVEL1].draw();
    else if(arr_view[LEVEL2].render) arr_view[LEVEL2].draw();
    else if(arr_view[LEVEL3].render) arr_view[LEVEL3].draw();
}

// render các nút bấm với trạng thái button_light khi con trỏ chuột nằm trong vùng button lên renderer
void Game::updateButtonDraw(const int var1, const int var2) 
{
    if(arr_view[var1].render)
    {
        if(SDL_PointInRect(&mousePoint, &arr_view[var1].dst))
        {
            arr_view[var2].draw();
            Game::display();
        }
    }
}

// update trạng thái của button có được render không bằng true / false 
// ví dụ: ban đầu nút level1 được gán giá trị true, còn level2 là false khi chọn level chơi là level1
void Game::updateRenderButton(const int var1, const int var2)
{
    arr_view[var1].render = false;
    arr_view[var2].render = true;
}

// lấy tọa độ hiện tại của con trỏ chuột
void Game::getMousePoint() 
{
    SDL_GetMouseState(&mouse_x, &mouse_y);
    mousePoint = {mouse_x, mouse_y};
}

// xử lý sự kiện trước khi chơi game
// ví dụ render trạng thái button_light khi con trỏ chuột ở vùng button
// hoặc thay đổi giá trị được render hay không của thay đổi ấn chuột thay đổi level
// hoặc xử lý sự kiện khi nút play được bấm
void Game::handleEventInView()
{
    SDL_PollEvent(&e);
    Game::handleEvent();
    Game::getMousePoint();
    Game::updateButtonDraw(PLAY, PLAY_LIGHT);
    Game::updateButtonDraw(LEVEL1, LEVEL1_LIGHT);
    Game::updateButtonDraw(LEVEL2, LEVEL2_LIGHT);
    Game::updateButtonDraw(LEVEL3, LEVEL3_LIGHT);
    Game::display();
    if(Game::status == GAME_PRE_PLAY)
    {
        if(Game::e.type == SDL_MOUSEBUTTONDOWN)
        {
            Game::getMousePoint();

            //click on play
            if(SDL_PointInRect(&mousePoint, &arr_view[PLAY].dst))
            {
                hello.draw();
                Game::display();
                Mix_PlayChannel(-1, music[CLICK], 0);
                Mix_PlayChannel(-1, music[HELLO_MUSIC], 0);
                SDL_Delay(5000);
                Game::status = GAME_PLAYING;
            }

            //click on level
            if(arr_view[LEVEL1].render && SDL_PointInRect(&mousePoint, &arr_view[LEVEL1].dst))
            {
                Game::updateRenderButton(LEVEL1, LEVEL2);
                Mix_PlayChannel(-1, music[CLICK], 0);
                Game::cnt_time = 700;
                arr_view[LEVEL2].draw();
            }
            else if(arr_view[LEVEL2].render && SDL_PointInRect(&mousePoint, &arr_view[LEVEL2].dst))
            {
                Game::updateRenderButton(LEVEL2, LEVEL3);
                Mix_PlayChannel(-1, music[CLICK], 0);
                Game::cnt_time = 500;
                arr_view[LEVEL3].draw();
            }
            else if(arr_view[LEVEL3].render && SDL_PointInRect(&mousePoint, &arr_view[LEVEL3].dst))
            {
                Game::updateRenderButton(LEVEL3, LEVEL1);
                Mix_PlayChannel(-1, music[CLICK], 0);
                Game::cnt_time = 1000;
                arr_view[LEVEL1].draw();
            }
             Game::display();
        }
    }

}

// trả lại true / false tương ứng với game có đang chạy không
bool Game::running()
{
    return is_running;
}

// reset lại renderer
void Game::clear()
{
    SDL_RenderClear(renderer);
}

// render màn hình khi chơi game ví dụ như: background, bảng để chơi, ô next, ô score lên renderer
void Game::renderBackground()
{   
    arr_object[BACKGROUND].draw();
    arr_object[CAT].draw();
    arr_object[BOARD].draw();
    //arr_object[HOLD].draw();
    arr_object[NEXT].draw();
    arr_object[SCORE].draw();
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

// hiện thị các đối tượng vẽ lên renderer lên màn hình
void Game::display()
{
    SDL_RenderPresent(renderer);
}

// xử lý trạng thái các nút bấm khi chơi game như: up, down, left, right, space
void Game::keyPresses()
{
    int x1 = this->board.x, y1 = this->board.y;
    int temp_m[4][4];
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) temp_m[i][j] = this->board.block.matrix[i][j];
    if(e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
            Mix_PlayChannel(-1, music[MOVE], 0);
            if(this->board.checkBorder(x1, y1 + 1))
            {
                this->board.x = x1;
                this->board.y = y1 + 1;
                this->board.block.updateXY(x1, y1 + 1);
            }
            break;
        case SDLK_LEFT:
            Mix_PlayChannel(-1, music[MOVE], 0);
            if(this->board.checkBorder(x1 - 1, y1))
            {
                bool ok = true;
                for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                if(this->board.block.matrix[i][j] && j - 1 < 0) {ok = false; break;}
                if(ok) 
                {
                    
                    for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++) this->board.block.matrix[i][j] = temp_m[i][(j + 1) % 4];
   
                }
                else
                {
                    this->board.x = x1 - 1;
                    this->board.y = y1;
                    this->board.block.updateXY(x1 - 1, y1);
                }
            }
            break;
        case SDLK_RIGHT:
            Mix_PlayChannel(-1, music[MOVE], 0);
            if(this->board.checkBorder(x1 + 1, y1))
            {
                bool ok = true;
                for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                if(this->board.block.matrix[i][j] && j + 1 > 3) {ok = false; break;}
                if(ok) 
                {
                    for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--) this->board.block.matrix[i][j] =  temp_m[i][(j - 1 + 4) % 4];
                }
                else
                {
                    this->board.x = x1 + 1;
                    this->board.y = y1;
                    this->board.block.updateXY(x1 + 1, y1);
                }
            }
            break;
        case SDLK_UP:
            Mix_PlayChannel(-1, music[ROTATE], 0);
            if(this->board.checkRotate(x1, y1) && this->board.block.curr_block != 2) 
            {
                this->board.block.rotate();
                this->board.block.updateXY(x1, y1);
            }
            break;
        case SDLK_SPACE:
            Mix_PlayChannel(-1, music[MOVE], 0);
            for(int i = 1; i <= 20; i++) 
            if(this->board.checkBorder(x1, i)) y1 = i; else break;
            this->board.y = y1;
            this->board.block.updateXY(x1, y1);
            this->board.updateBoard();
            this->board.new_block = true;
            SDL_Delay(100);
            break;
        default:
            break;
        }    
    }

}

// kiểm tra xem có gameover chưa
int Game::checkGameOver()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(this->board.block.matrix[i][j])
            {

                if(this->board.board[this->board.block.xy[i][j].y][this->board.block.xy[i][j].x])
                {
                    this->status = GAME_OVER;
                }
            }
        }
    }
    return this->status;
}

// cho khối block rơi thêm xuống một hàng
void Game::downBlock()
{
    this->curr_time = SDL_GetTicks();
    if(this->curr_time - this->prev_time > this->cnt_time) {
        this->prev_time = this->curr_time;
        if(this->board.checkCanDown(this->board.x, this->board.y + 1)) 
        {
            this->board.y = this->board.y + 1;
            this->board.block.updateXY(this->board.x, this->board.y);
            Mix_PlayChannel(-1, music[MOVE], 0);
        }
        else
        {
            if(this->checkGameOver())
            {
                this->status = GAME_OVER;
            }
            else
            {
                this->board.updateBoard();
                this->board.new_block = true;
            }
        }
    }
}

// update số dòng full các ô gạch tạo được
void Game::updateLine(int val)
{
    this->cnt_line += val;
}

// update số điểm đạt được
void Game::updateScore(int val)
{
    switch (val)
    {
    case 1:
        cnt_score += 5;
        break;
    case 2:
        cnt_score += 20;
        break;
    case 3:
        cnt_score += 60;
        break;
    case 4:
        cnt_score += 160;
        break;
    default:
        break;
    }
}

// hiện thị số dòng tạo được lên phần line trong ô score
void Game::showLine()
{
    string s = to_string(this->cnt_line);
    SDL_Color color = {225, 225, 225};
    this->line.loadFromeRenderText(s, color);
    this->line.setDst({this->arr_object[SCORE].dst.x + (250 - this->line.dst.w) / 2, YPOS + 270, this->line.dst.w, this->line.dst.h});
    this->line.draw();

}

// hiện thị số điểm đạt được trong phần score trong ô score
void Game::showScore()
{
    string s = to_string(this->cnt_score);
    SDL_Color color = {255, 255, 255};
    this->score.loadFromeRenderText(s, color);
    this->score.setDst({this->arr_object[SCORE].dst.x + (250 - this->score.dst.w) / 2, YPOS + 111, this->score.dst.w, this->score.dst.h});
    this->score.draw();
}

// vẽ màn hình gameover
void Game::showScoreGameOver()
{
    string s = to_string(this->cnt_score);
    SDL_Color color = {255, 255, 255};
    this->score.loadFromeRenderText(s, color);
    this->score.setDst({this->game_over.dst.x + (300 - this->score.dst.w) / 2, this->game_over.dst.y + 116, this->score.dst.w, this->score.dst.h});
    this->score.draw();
    Game::showScore();
    Game::showLine();
}

// xử lý sự kiện e.type == SDL_QUIT
void Game::handleEvent()
{
    if(e.type == SDL_QUIT)
    {
        is_running = false;
    }
}

// xử lý trạng thái game
// ví dụ như: game_over, game_playing, tạo block mới
void Game::handleStatus()
{
    // tạo block mới
    if(this->board.new_block) 
    {
        this->board.block = this->board.next_block;
        this->board.next_block = Block();
        this->board.new_block = false;
        this->board.x = DIS_X, this->board.y = DIS_Y;
    }

    if(Game::status == GAME_PLAYING) 
    {
        SDL_PollEvent(&e);
        Game::handleEvent();
        if(this->checkGameOver()) {
            this->status = GAME_OVER;
        }
        int val = this->board.checkCreateRow();
        if(val) Mix_PlayChannel(-1, music[LINECLEAR], 0);
        Game::updateLine(val);
        Game::updateScore(val);
        Game::showScore();
        Game::showLine();
        this->board.showBoard();
        Game::downBlock();
        Game::keyPresses();
        this->board.showBlock();
        Game::display();
        
    }

    if(Game::status == GAME_OVER)
    {
        SDL_PollEvent(&e);
        Game::handleEvent();
        this->board.showBoard();
        this->board.showBlock();
        this->game_over.draw();
        if(home.render) this->home.draw();
        if(home_light.render) this->home_light.draw();
        Game::showScoreGameOver();
        Game::display();
        if(cnt_gameover == 0){
            Mix_PlayChannel(-1, music[GAMEOVER], 0);
            SDL_Delay(3000);
            cnt_gameover = 1;
        }
        Game::getMousePoint();
        if(SDL_PointInRect(&mousePoint, &home.dst))
        {
            home_light.draw();
            home_light.render = true;
            home.render = false;
            Game::display();
        }
        else 
        {
            home_light.render = false;
            home.render = true;
        }
        
        if(Game::e.type == SDL_MOUSEBUTTONDOWN)
        {   
            //click on home
            if(SDL_PointInRect(&mousePoint, &home.dst))
            {
                Game::status = GAME_PRE_PLAY;
                Mix_PlayChannel(-1, music[CLICK], 0);
            }
        }
        
        
    }

}