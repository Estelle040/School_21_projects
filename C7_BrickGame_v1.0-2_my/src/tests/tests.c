/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "./tests/0.include.check" instead.
 */

#include <check.h>

#include "../../src/brick_game/tetris/tetris.h"
#include "../../src/brick_game/tetris/backend.h"
#include "../../src/brick_game/tetris/fsm.h"



START_TEST(calculateTet_test_counterIter_is_full)
{
TetGame_t * game = initGame();
game->counterIter = COUNT_ITERATION * 15 / game->gameInfo->speed;
calculateTet(game);
ck_assert_int_eq(game->counterIter , 0);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Right_success_1)
{
TetGame_t * game = initGame();
game->figure->x = 2;
game->figure->y= 2;
game->action = Right;
calculateTet(game);
int x_end = 3;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Right_success_2)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(1);
game->figure->x = WIDTH_FIELD - 5;
game->figure->y= 2;
game->action = Right;
calculateTet(game);
int x_end = WIDTH_FIELD - 4;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Right_unsuccess_1)
{
TetGame_t * game = initGame();
game->figure->x = WIDTH_FIELD;
game->figure->y= 2;
game->action = Right;
calculateTet(game);
int x_end = WIDTH_FIELD;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Left_success_1)
{
TetGame_t * game = initGame();
game->figure->x = 2;
game->figure->y= 2;
game->action = Left;
calculateTet(game);
int x_end = 1;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Left_success_2)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(1);
game->figure->x = 0;
game->figure->y= 2;
game->action = Left;
calculateTet(game);
int x_end = -1;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Left_unsuccess_1)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(1);
game->figure->x = -1;
game->figure->y= 2;
game->action = Left;
calculateTet(game);
int x_end = -1;
ck_assert_int_eq(game->figure->x , x_end);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Up_success_1)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(1);
game->figure->y= 5;
game->action = Up;
calculateTet(game);
int ** blocks = game->figure->blocks;
int sumBLocks = blocks[1][2] + blocks[2][1] +
            blocks[2][2] + blocks[3][2];
ck_assert_int_eq(sumBLocks , 4);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Down_success_1)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(2);
game->figure->y= HEIGHT_FIELD - 3;
game->action = Down;
calculateTet(game);
int ** blocks = game->field->blocks;
int sumBLocks = 0;
for (int i = 0; i < WIDTH_FIELD; i++){
    sumBLocks += blocks[HEIGHT_FIELD - 1][i];
}
ck_assert_int_eq(sumBLocks , 4);
freeGame(game);


}
END_TEST

START_TEST(calculateTet_test_Down_success_2)
{
TetGame_t * game = initGame();
free(game->figure);
game->figure = createRandomFigure(2);
game->figure->y= HEIGHT_FIELD - 3;
game->counterIter = COUNT_ITERATION * 15 / game->gameInfo->speed;
calculateTet(game);
int ** blocks = game->field->blocks;
int sumBLocks = 0;
for (int i = 0; i < WIDTH_FIELD; i++){
    sumBLocks += blocks[HEIGHT_FIELD - 1][i];
}
ck_assert_int_eq(sumBLocks , 4);
freeGame(game);
}
END_TEST

START_TEST(createField_test_1)
{

Field_t * field = createField();
ck_assert_ptr_nonnull(field);
freeField(field);
}
END_TEST

START_TEST(createFigure_test_1)
{
Figure_t * figure = createRandomFigure(0);
ck_assert_ptr_nonnull(figure);
freeFigure(figure);


}
END_TEST

START_TEST(updateFigure_test_1)
{
TetGame_t * game = initGame();
DropNewFigure(game);
int y_start = -5;
ck_assert_ptr_nonnull(game->figure);
ck_assert_int_eq(game->figure->y , y_start);
freeGame(game);


}
END_TEST

START_TEST(placeFigure_test_1)
{
TetGame_t * game = initGame();
freeFigure(game->figure);
game->figure = createRandomFigure(2);
game->figure->y = HEIGHT_FIELD - 3;
plantFigure(game);
int sumBLocks = 0;
for (int i = 0; i < WIDTH_FIELD; i++){
    
    sumBLocks += game->field->blocks[HEIGHT_FIELD - 1][i];
}
ck_assert_int_eq(sumBLocks, 4);
freeGame(game);
}
END_TEST

START_TEST(createGame_test_1)
{

TetGame_t * game = createGame();
ck_assert_ptr_nonnull(game);
freeGame(game);

}
END_TEST

START_TEST(updateCurrentState_test_1)
{
TetGame_t * game = initGame();
TetGame_t * game_new =  updateCurrentState(game);
ck_assert_ptr_nonnull(game);
freeGame(game);
}
END_TEST

START_TEST(moveDown_test_succes)
{
Figure_t * figure = createRandomFigure(0);
figure->y = 1;
int y_end = 2;
moveDown(figure);
ck_assert_int_eq(y_end, figure->y);
freeFigure(figure);


}
END_TEST

START_TEST(moveLeft_test_succes)
{
Figure_t * figure = createRandomFigure(0);
figure->x = 5;
int x_end = 4;
moveLeft(figure);
ck_assert_int_eq(x_end, figure->x);
freeFigure(figure);


}
END_TEST

START_TEST(moveRight_test_succes)
{
Figure_t * figure = createRandomFigure(0);
figure->x = 5;
int x_end = 6;
moveRight(figure);
ck_assert_int_eq(x_end, figure->x);
freeFigure(figure);


}
END_TEST

START_TEST(moveUp_test_succes)
{
Figure_t * figure = createRandomFigure(0);
figure->y = 5;
int y_end = 4;
moveUp(figure);
ck_assert_int_eq(y_end, figure->y);
freeFigure(figure);

}
END_TEST


START_TEST(userAction_test_KEY_UP)
{
TetGame_t * game = initGame();
int ch = KEY_UP;
userAction(game,ch);
ck_assert_int_eq(game->action , Up);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_KEY_DOWN)
{
TetGame_t * game = initGame();
int ch = KEY_DOWN;
userAction(game,ch);
ck_assert_int_eq(game->action , Down);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_KEY_LEFT)
{
TetGame_t * game = initGame();
int ch = KEY_LEFT;
userAction(game,ch);
ck_assert_int_eq(game->action , Left);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_KEY_RIGHT)
{
TetGame_t * game = initGame();
int ch = KEY_RIGHT;
userAction(game,ch);
ck_assert_int_eq(game->action , Right);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_q)
{
TetGame_t * game = initGame();
int ch =  'q';
userAction(game,ch);
ck_assert_int_eq( game->gameStatus , Terminate);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_p_1)
{
TetGame_t * game = initGame();
int ch =  'p';
userAction(game,ch);
ck_assert_int_eq( game->gameStatus , Pause);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_p_2)
{
TetGame_t * game = initGame();
game->gameStatus = Pause;
int ch =  'p';
userAction(game,ch);
ck_assert_int_eq( game->gameStatus , Start);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_increase_speed_1)
{
TetGame_t * game = initGame();
int speed_end = game->gameInfo->speed + 1;
int ch =  '+';
userAction(game,ch);
ck_assert_int_eq(game->gameInfo->speed , speed_end);
freeGame(game);

}
END_TEST

START_TEST(userAction_test_increase_speed_2)
{
TetGame_t * game = initGame();
game->gameInfo->speed = 10;
int speed_end = game->gameInfo->speed;
int ch =  '+';
userAction(game,ch);
ck_assert_int_eq(game->gameInfo->speed , speed_end);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_reduce_speed_1)
{
TetGame_t * game = initGame();
game->gameInfo->speed = 5;
int speed_end = game->gameInfo->speed - 1;
int ch =  '-';
userAction(game,ch);
ck_assert_int_eq(game->gameInfo->speed , speed_end);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_reduce_speed_2)
{
TetGame_t * game = initGame();
game->gameInfo->speed = 1;
int speed_end = game->gameInfo->speed;
int ch =  '-';
userAction(game,ch);
ck_assert_int_eq(game->gameInfo->speed , speed_end);
freeGame(game);


}
END_TEST

START_TEST(userAction_test_reduce_speed_3)
{
TetGame_t * game = initGame();
game->gameInfo->speed = 2;
game->gameInfo->level = 2;
int speed_end = game->gameInfo->speed;
int ch =  '-';
userAction(game,ch);
ck_assert_int_eq(game->gameInfo->speed , speed_end);
freeGame(game);




}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("calculateTet");
    TCase *tc1_1 = tcase_create("calculateTet");
    Suite *s2 = suite_create("field");
    TCase *tc2_1 = tcase_create("field");
    Suite *s3 = suite_create("figure");
    TCase *tc3_1 = tcase_create("figure");
    Suite *s4 = suite_create("game");
    TCase *tc4_1 = tcase_create("game");
    Suite *s5 = suite_create("moveFigure");
    TCase *tc5_1 = tcase_create("moveFigure");
    Suite *s6 = suite_create("userAction");
    TCase *tc6_1 = tcase_create("userAction");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, calculateTet_test_counterIter_is_full);
    tcase_add_test(tc1_1, calculateTet_test_Right_success_1);
    tcase_add_test(tc1_1, calculateTet_test_Right_success_2);
    tcase_add_test(tc1_1, calculateTet_test_Right_unsuccess_1);
    tcase_add_test(tc1_1, calculateTet_test_Left_success_1);
    tcase_add_test(tc1_1, calculateTet_test_Left_success_2);
    tcase_add_test(tc1_1, calculateTet_test_Left_unsuccess_1);
    tcase_add_test(tc1_1, calculateTet_test_Up_success_1);
    tcase_add_test(tc1_1, calculateTet_test_Down_success_1);
    tcase_add_test(tc1_1, calculateTet_test_Down_success_2);
    suite_add_tcase(s2, tc2_1);
    tcase_add_test(tc2_1, createField_test_1);
    suite_add_tcase(s3, tc3_1);
    tcase_add_test(tc3_1, createFigure_test_1);
    tcase_add_test(tc3_1, updateFigure_test_1);
    tcase_add_test(tc3_1, placeFigure_test_1);
    suite_add_tcase(s4, tc4_1);
    tcase_add_test(tc4_1, createGame_test_1);
    tcase_add_test(tc4_1, updateCurrentState_test_1);
    suite_add_tcase(s5, tc5_1);
    tcase_add_test(tc5_1, moveDown_test_succes);
    tcase_add_test(tc5_1, moveLeft_test_succes);
    tcase_add_test(tc5_1, moveRight_test_succes);
    tcase_add_test(tc5_1, moveUp_test_succes);
    suite_add_tcase(s6, tc6_1);
    tcase_add_test(tc6_1, userAction_test_KEY_UP);
    tcase_add_test(tc6_1, userAction_test_KEY_DOWN);
    tcase_add_test(tc6_1, userAction_test_KEY_LEFT);
    tcase_add_test(tc6_1, userAction_test_KEY_RIGHT);
    tcase_add_test(tc6_1, userAction_test_q);
    tcase_add_test(tc6_1, userAction_test_p_1);
    tcase_add_test(tc6_1, userAction_test_p_2);
    tcase_add_test(tc6_1, userAction_test_increase_speed_1);
    tcase_add_test(tc6_1, userAction_test_increase_speed_2);
    tcase_add_test(tc6_1, userAction_test_reduce_speed_1);
    tcase_add_test(tc6_1, userAction_test_reduce_speed_2);
    tcase_add_test(tc6_1, userAction_test_reduce_speed_3);

    srunner_add_suite(sr, s2);
    srunner_add_suite(sr, s3);
    srunner_add_suite(sr, s4);
    srunner_add_suite(sr, s5);
    srunner_add_suite(sr, s6);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
