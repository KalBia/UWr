#include <iostream>
#include "game_state.hpp"
#include "game_AI.hpp"
#include "game_interface.hpp"

//*******************************************

int main()
{
    game_state::board GAME = game_state::board();
    int move;

    game_interface::display(GAME);
    while (game_interface::end_game(GAME) == 0)
    {
        if (GAME.get_who()) // ruch gracza
        {
            move = game_interface::ask_player_for_move();
            GAME.update_board(move);
        }
        else // ruch komputera
        {
            game_interface::computer_move();
            move = game_AI::make_move(GAME);
            GAME.update_board(move);
        }

        game_interface::display(GAME);
    }
}

//*******************************************