
#include "tetris.h"

#include <ncurses.h>

#include "../../gui/cli/frontend.h"
#include "backend.h"
#include "fsm.h"
#include "ncurses.h"

// Создать фигуру заполненную нулями
Figure_t *createFigure() {
  Figure_t *figure = (Figure_t *)malloc(sizeof(Figure_t));
  figure->blocks = (int **)calloc(FIGURE_SIZE, sizeof(int *));
  for (int row = 0; row < FIGURE_SIZE; row++) {
    figure->blocks[row] = (int *)calloc(FIGURE_SIZE, sizeof(int));
  }
  figure->y = 0;
  return figure;
}

// Освободить выделенную для фигуры память
void freeFigure(Figure_t *figure) {
  if (figure) {
    if (figure->blocks) {
      for (int row = 0; row < FIGURE_SIZE; row++) {
        if (figure->blocks[row]) {
          free(figure->blocks[row]);
        }
      }
      free(figure->blocks);
    }
    free(figure);
  }
}

// Создать поле размером HEIGHT_FIELD на WIGHT_FIELD заполненное нулями
Field_t *createField() {
  Field_t *field = (Field_t *)malloc(sizeof(Field_t));
  field->blocks = (int **)calloc(HEIGHT_FIELD, sizeof(int *));
  for (int row = 0; row < HEIGHT_FIELD; row++) {
    field->blocks[row] = (int *)calloc(WIDTH_FIELD, sizeof(int));
  }
  return field;
}

// Освободить выделенную для поля память
void freeField(Field_t *field) {
  if (field) {
    if (field->blocks) {
      for (int row = 0; row < HEIGHT_FIELD; row++) {
        if (field->blocks[row]) {
          free(field->blocks[row]);
        }
      }
      free(field->blocks);
    }
    free(field);
  }
}

// Создать игру
TetGame_t *createGame() {
  TetGame_t *game = (TetGame_t *)malloc(sizeof(TetGame_t));
  game->gameInfo = (GameInfo_t *)malloc(sizeof(GameInfo_t));

  return game;
}

// Освободить выделенную для игры память
void freeGame(TetGame_t *game) {
  if (game) {
    freeFigure(game->figure);
    freeFigure(game->figureNext);
    freeField(game->field);
    free(game->gameInfo);
    free(game);
  }
}
