#ifndef BACKEND_H
#define BACKEND_H

#include "tetris.h"

// Создать фигуру из паттернов
Figure_t *createRandomFigure(int number);

// Движение фигуры по Y вниз
void moveDown(Figure_t *figure);

// Движение фигуры по Y вверх
void moveUp(Figure_t *figure);

// Движение фигуры по X влево
void moveLeft(Figure_t *figure);

// Движение фигуры по X вправо
void moveRight(Figure_t *figure);

// Поворот фигуры
void rotateFigure(Figure_t *figure);

// Выкинуть новую фигуру
void DropNewFigure(TetGame_t *game);

// Проверяет находится ли блок в пределах игрового поля
int checkBoundaries(int row, int col, int fy, int fx);

// Проверка столкновения фигуры
int collisionFigure(TetGame_t *game);

// Установить фигуру на поле
void plantFigure(TetGame_t *game);

// Проверяет заполнена ли линия под индексом row
int lineIsFill(Field_t *field, int row);

// Удаляет строку
void dropLine(Field_t *field, int row);

// Удаляет строки и подсчитывает результат
int eraseLines(TetGame_t *game);

// Увеличение уровня в зависимости от score
void levelUp(TetGame_t *game);

// Переводит кол-во уничтоженных уровней (строк) в score
int converterScore(int count_rows);

// Читает из базы данных максимальный score
int readDataBase();

// Записывает в базу данных максимальный score
int writeDataBase(int score);
#endif