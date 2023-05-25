#include <iostream>
#include "game_state.hpp"

//*******************************************

game_state::board::board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j] = ' ';
        }
    }

    who_plays_now = true;
}

//*******************************************

void game_state::board::update_board(int move)
{
    int i = move / 3;
    int j = move % 3;

    if (tab[i][j] != ' ')
    {
        std::cout<< "You can't make this move. Try again.\n\n";
        return;
    }

    if (who_plays_now)
        tab[i][j] = 'X';
    else
        tab[i][j] = 'O';

    who_plays_now = !who_plays_now;
}

//*******************************************

char game_state::board::get_board_box(int move)
{
    return tab[move / 3][move % 3];
}

//*******************************************

bool game_state::board::get_who()
{
    return who_plays_now;
}

//*******************************************

int game_state::someone_won(game_state::board game)
{
    if ( (game.get_board_box(0) == game.get_board_box(4) && game.get_board_box(0) == game.get_board_box(8) && game.get_board_box(0) != ' ')  // przekątna 1
            ||
         (game.get_board_box(0) == game.get_board_box(1) && game.get_board_box(0) == game.get_board_box(2) && game.get_board_box(0) != ' ')  // poziom 1
            ||
         (game.get_board_box(0) == game.get_board_box(3) && game.get_board_box(0) == game.get_board_box(6) && game.get_board_box(0) != ' ')  // pion 1
         )
    {
        if (game.get_board_box(0) == 'X')
        {
            return 1; //player won
        }
        
        return 2; //computer won
    }

    if ( (game.get_board_box(2) == game.get_board_box(4) && game.get_board_box(2) == game.get_board_box(6) && game.get_board_box(4) != ' ')  // przekątna 2
            ||
         (game.get_board_box(3) == game.get_board_box(4) && game.get_board_box(3) == game.get_board_box(5) && game.get_board_box(4) != ' ')  // poziom 2
            ||
         (game.get_board_box(1) == game.get_board_box(4) && game.get_board_box(1) == game.get_board_box(7) && game.get_board_box(4) != ' ')  // pion 2
         )
    {
        if (game.get_board_box(4) == 'X')
        {
            return 1;
        }
        
        return 2;
    }
    
    if ( (game.get_board_box(6) == game.get_board_box(7) && game.get_board_box(6) == game.get_board_box(8) && game.get_board_box(8) != ' ')  // poziom 3
            ||
         (game.get_board_box(2) == game.get_board_box(5) && game.get_board_box(2) == game.get_board_box(8) && game.get_board_box(8) != ' ')  // pion 3
        )
    {
        if (game.get_board_box(8) == 'X')
        {
            return 1;
        }
        
        return 2;
    }

    return 0;
}

//*******************************************

bool game_state::no_moves(game_state::board game)
{
    bool result = true;
    int move = 0;
    while (move < 9 && game.get_board_box(move) != ' ')
        move += 1;
    
    if (move == 9)
        return true;
    return false;
}

//*******************************************