#include <iostream>
#include <time.h>
#include "game_AI.hpp"

//*******************************************

bool game_AI::is_good_move(int move, game_state::board game) 
{
    if (game.get_board_box(move) != ' ')
        return false;
    return true;
}

//*******************************************

int game_AI::make_move(game_state::board game)
{
    srand(time(0));
    int move = rand() % 9;
    while (!is_good_move(move, game))
        move = rand() % 9;

    return move;
}

//*******************************************