#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../brick_game/tetris/backend.h"
#include "../brick_game/tetris/tetris.h"
#include "../brick_game/tetris/fsm.h"
#include "tetris/tetris.h"
#include "tetris/backend.h"
#include "../gui/cli/frontend.h"
#include "ncurses.h"
#include "tetris/fsm.h"
#include <ncurses.h>

int tetrisGame(TetWindows_t *winTet);

int main()
{
    TetWindows_t *winTet = tetrisGUI();
    tetrisGame(winTet);

    return 0;
}

int tetrisGame(TetWindows_t *winTet)
{
    TetGame_t *game = initGame();
    while (game->gameStatus != Terminate)
    {   
        int ch = getch();
        userAction(game, ch);
        if (game->gameStatus != Pause)
        {
            updateCurrentState(game);
        }
        usleep(2000);
        if (winTet)
            frontend(game, winTet);
    }
    freeGame(game);
    if (winTet)
    {
        freeWindows(winTet);
        endwin();
    }

    return 0;
}
