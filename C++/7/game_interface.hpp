#ifndef game_interface_h
#define game_interface_h
#include "game_state.hpp"

//*******************************************

namespace game_interface
{
    const int type_of_moves[3][3] = { {0 , 1 , 2} , {3 , 4 , 5}, {6 , 7 , 8} };

    void display (game_state::board);
    int ask_player_for_move();
    void computer_move();
    bool end_game(game_state::board);
}

//*******************************************

#endif