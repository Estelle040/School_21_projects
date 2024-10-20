#ifndef FSM_H
#define FSM_H

#include "tetris.h"
#include "../../gui/cli/frontend.h"

// Функция для просчета одной итерации
void calculateTet(TetGame_t *game);

// Обновляет текущий состояние игры
TetGame_t *updateCurrentState(TetGame_t *game);

// Изменение состояний игры в зависимости от действий игрока
void userAction(TetGame_t *game, int ch);

// Инициализация игры
TetGame_t *initGame();

#endif