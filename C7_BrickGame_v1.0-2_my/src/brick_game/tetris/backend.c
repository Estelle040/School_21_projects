#include "backend.h"

#include "tetris.h"

Figure_t *createRandomFigure(int number) {
  Figure_t *figure = createFigure();

  if (number == 0) number = rand() % 7 + 1;

  char fileName[20];
  sprintf(fileName, "./FigureTypes/%d.txt", number);
  FILE *file = fopen(fileName, "r");
  if (file) {
    char ch;
    int elem = 0;
    while ((ch = fgetc(file)) != EOF) {
      int number = ch - '0';
      if (number == 1 || number == 0) {
        figure->blocks[elem / 5][elem % 5] = number;
        elem++;
      }
    }
  }
  figure->color = (number + rand()) % 4 + 3;
  fclose(file);
  return figure;
}

void moveDown(Figure_t *figure) { figure->y++; }

void moveUp(Figure_t *figure) { figure->y--; }

void moveLeft(Figure_t *figure) { figure->x--; }

void moveRight(Figure_t *figure) { figure->x++; }

void rotateFigure(Figure_t *figure) {
  Figure_t *figureTmp = createFigure();
  for (int row = 0; row < FIGURE_SIZE; row++) {
    for (int col = 0; col < FIGURE_SIZE; col++) {
      figureTmp->blocks[col][row] = figure->blocks[row][FIGURE_SIZE - col - 1];
    }
  }
  for (int row = 0; row < FIGURE_SIZE; row++) {
    for (int col = 0; col < FIGURE_SIZE; col++) {
      figure->blocks[col][row] = figureTmp->blocks[col][row];
    }
  }

  freeFigure(figureTmp);
}

void DropNewFigure(TetGame_t *game) {
  freeFigure(game->figure);
  game->figure = game->figureNext;
  game->figure->x = FIGURE_START_X;

  game->figure->y = -5;
  game->figureNext = createRandomFigure(0);
}

int checkBoundaries(int row, int col, int fy, int fx) {
  int result = 1;
  if ((row + fy > HEIGHT_FIELD - 1 || row + fy < 0) ||
      (col + fx > WIDTH_FIELD - 1 || col + fx < 0))
    result = 0;
  return result;
}

void plantFigure(TetGame_t *game) {
  int fy = game->figure->y;
  int fx = game->figure->x;

  for (int row = 0; row < FIGURE_SIZE; row++) {
    for (int col = 0; col < FIGURE_SIZE; col++) {
      int fgr = game->figure->blocks[row][col];
      if (fgr != 0 && fy + row >= 0) {
        game->field->blocks[fy + row][fx + col] = fgr;
      }
    }
  }
}

int lineIsFill(Field_t *field, int row) {
  int result = 1;
  for (int col = 0; col < WIDTH_FIELD; col++) {
    int block = field->blocks[row][col];
    if (block == 0) result = 0;
  }
  return result;
}

void dropLine(Field_t *field, int row) {
  if (row == HEIGHT_FIELD) {
    for (int col = 0; col < WIDTH_FIELD; col++) field->blocks[row][col] = 0;
  } else {
    for (int i = row; i > 0; i--) {
      for (int col = 0; col < WIDTH_FIELD; col++) {
        field->blocks[i][col] = field->blocks[i - 1][col];
      }
    }
  }
}

int eraseLines(TetGame_t *game) {
  int counter = 0;
  for (int row = HEIGHT_FIELD - 1; row >= 0; row--) {
    while (lineIsFill(game->field, row)) {
      dropLine(game->field, row);
      counter++;
    }
  }
  return counter;
}

int collisionFigure(TetGame_t *game) {
  int result = 0;

  int fx = game->figure->x;
  int fy = game->figure->y;

  int **figure = game->figure->blocks;
  int **field = game->field->blocks;

  for (int row = 0; row < FIGURE_SIZE; row++) {
    for (int col = 0; col < FIGURE_SIZE; col++) {
      int fgr = figure[row][col];

      if (fgr == 1) {
        if (fy + row < 0)
          continue;

        else if (checkBoundaries(row, col, fy, fx)) {
          int fld = field[fy + row][fx + col];

          if (fgr != 0 && fld != 0) {
            result = 1;

            if (fy + row == 0) game->gameStatus = GameOver;

            break;
          }
        }

        else if (!checkBoundaries(row, col, fy, fx)) {
          result = 1;
          break;
        }
      }
    }
    if (result) break;
  }
  return result;
}

void levelUp(TetGame_t *game) {
  int sc = game->gameInfo->score;
  game->gameInfo->level = 1 + sc / 600;

  while (game->gameInfo->speed < game->gameInfo->level) {
    game->gameInfo->speed++;
  }
}

int converterScore(int count_rows) {
  int result = 0;
  if (count_rows == 1)
    result = 100;

  else if (count_rows == 2)
    result = 300;

  else if (count_rows == 3)
    result = 700;

  else if (count_rows >= 4)
    result = 1500;

  return result;
}

int readDataBase() {
  int score = 0;
  char fileName[] = "./record/data.txt";
  FILE *file = fopen(fileName, "r");
  if (file) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch >= '0' && ch <= '9') {
        score = score * 10 + (ch - '0');
      } else {
        break;
      }
    }
  }

  fclose(file);
  return score;
}

int writeDataBase(int score) {
  char fileName[] = "./record/data.txt";
  FILE *file = fopen(fileName, "w");
  if (file) {
    fprintf(file, "%d", score);
  }

  fclose(file);
  return 0;
}
