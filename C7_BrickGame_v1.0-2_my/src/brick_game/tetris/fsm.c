#ifndef FSM_C
#define FSM_C

#include "fsm.h"

#include "backend.h"
#include "ncurses.h"
#include "tetris.h"

void calculateTet(TetGame_t *game) {
  if (game->counterIter >= COUNT_ITERATION * 15 / game->gameInfo->speed) {
    game->counterIter = 0;
    moveDown(game->figure);

    if (collisionFigure(game)) {
      moveUp(game->figure);
      plantFigure(game);
      int count_rows = eraseLines(game);
      game->gameInfo->score =
          game->gameInfo->score + converterScore(count_rows);
      levelUp(game);
      DropNewFigure(game);
      if (collisionFigure(game)) {
        game->gameStatus = GameOver;
      }
    }
  } else {
    switch (game->action) {
      case Right: {
        moveRight(game->figure);
        if (collisionFigure(game)) moveLeft(game->figure);
        break;
      }
      case Left: {
        moveLeft(game->figure);
        if (collisionFigure(game)) moveRight(game->figure);
        break;
      }
      case Up: {
        rotateFigure(game->figure);
        if (collisionFigure(game))
          for (int i = 0; i < 3; i++) {
            rotateFigure(game->figure);
          }
        break;
      }
      case Down: {
        moveDown(game->figure);
        if (collisionFigure(game)) {
          moveUp(game->figure);
          plantFigure(game);
          int count_rows = eraseLines(game);
          game->gameInfo->score =
              game->gameInfo->score + converterScore(count_rows);
          levelUp(game);
          DropNewFigure(game);
          if (collisionFigure(game)) {
            game->gameStatus = GameOver;
          }
        }
        break;
      }
      case Action:
      default:
        break;
    }
    game->counterIter++;
  }
}

void userAction(TetGame_t *game, int ch) {
  switch (ch) {
    case KEY_UP:
      game->action = Up;
      break;
    case KEY_DOWN:
      game->action = Down;
      break;
    case KEY_LEFT:
      game->action = Left;
      break;
    case KEY_RIGHT:
      game->action = Right;
      break;
    case 'q':
      game->gameStatus = Terminate;
      break;
    case 'p':
      if (game->gameStatus == Pause)
        game->gameStatus = Start;
      else if ((game->gameStatus != GameOver))
        game->gameStatus = Pause;
      break;
    case '+':
    case '=':
      if (game->gameInfo->speed > 0 && game->gameInfo->speed < 10)
        game->gameInfo->speed++;
      break;
    case '_':
    case '-':
      if (game->gameInfo->speed > 1 && game->gameInfo->speed <= 10 &&
          game->gameInfo->speed > game->gameInfo->level)
        game->gameInfo->speed--;
      break;

    default:
      game->action = Action;
      break;
  }
}

TetGame_t *updateCurrentState(TetGame_t *game) {
  calculateTet(game);
  if (game->gameInfo->score > game->gameInfo->record) {
    game->gameInfo->record = game->gameInfo->score;
    writeDataBase(game->gameInfo->record);
  }
  return game;
}
#endif

TetGame_t *initGame() {
  srand((unsigned)time(NULL));

  TetGame_t *game = createGame();

  game->figure = createRandomFigure(0);
  game->figure->x = FIGURE_START_X;

  game->figureNext = createRandomFigure(0);
  game->field = createField();

  game->action = Start;

  game->gameInfo->level = 1;
  game->gameInfo->record = readDataBase();

  game->gameInfo->score = 0;
  game->gameInfo->speed = START_SPEED;

  game->counterIter = 1;

  return game;
}
