#pragma once
#include <iostream>

#define endl '\n'
const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 800;

const int FPS = 60;
const int FPS_time = 1000 / FPS;

const int XPOS = (SCREEN_WIDTH - 350) / 2;
const int YPOS = (SCREEN_HEIGHT - 700) / 2;

const int LENGTH_SQUARE = 35;
const int ROW = 22;
const int COLUM = 12;
const int DIS_X = (COLUM - 4) / 2;
const int DIS_Y = 1;

const int NEW_ELEMENT_OBJECT = 7;
const int BACKGROUND = 0;
// const int HOLD = 1;
const int NEXT = 2;
const int SCORE = 3;
const int CAT = 4;
const int BOARD = 5;
const int BRICK = 6;

const int TYPE_BLOCK[7][4] = {
                                {2, 6, 10, 11}, //L
                                {3, 7, 10, 11}, //_|
                                {2, 3, 6, 7}, //O
                                {2, 3, 5, 6}, //S
                                {2, 3, 7, 8}, //2
                                {2, 6, 7, 10}, //-|
                                {2, 6, 10, 14}, //|
};


const int GAME_PLAYING = 0;
const int GAME_PRE_PLAY = 1;
const int GAME_OVER = 2;


const int NEW_ELEMENT_VIEW = 10;
const int BOARD_BACKGROUND = 0;
const int PLAY = 1;
const int PLAY_LIGHT = 2;
const int LEVEL1 = 3;
const int LEVEL1_LIGHT = 4;
const int LEVEL2 = 5;
const int LEVEL2_LIGHT = 6;
const int LEVEL3 = 7;
const int LEVEL3_LIGHT = 8;
const int TETRIS = 9;


const int NEW_ELEMENT_MUSIC = 10;
const int BACKGROUND_MUSIC = 0;
const int HELLO_MUSIC = 1;