#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define FIGURE_SIZE 5
#define HEIGHT_FIELD 20
#define WIDTH_FIELD 10

#define FIGURE_START_Y 0
#define FIGURE_START_X WIDTH_FIELD / 2 - 3;
#define SHIFT_FIELD_X 5
#define SHIFT_FIELD_Y 5

#define COUNT_ITERATION 30
#define START_SPEED 1

typedef struct Figure_t
{
    int **blocks;
    int color;
    int x;
    int y;

} Figure_t;

typedef struct Player_t
{
    int action;
} Player_t;

typedef struct Field_t
{
    int **blocks;
} Field_t;

typedef enum
{
    Start,
    Pause,
    GameOver,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action

} UserAction_t;

typedef struct GameInfo_t
{
    int speed;
    int score;
    int record;
    int level;

} GameInfo_t;
;

typedef struct TetGame_t
{
    Figure_t *figure;
    Figure_t *figureNext;
    Player_t *player;
    Field_t *field;
    GameInfo_t *gameInfo;

    int action;
    int counterIter;
    int gameStatus;

} TetGame_t;

// Создать фигуру заполненную нулями
Figure_t *createFigure();

// Освободить выделенную для фигуры память
void freeFigure(Figure_t *figure);

// Создать поле размером HEIGHT_FIELD на WIGHT_FIELD заполненное нулями
Field_t *createField();

// Освободить выделенную для поля память
void freeField(Field_t *field);

// Создать игру
TetGame_t *createGame();

// Освободить выделенную для игры память
void freeGame(TetGame_t *game);

#endif