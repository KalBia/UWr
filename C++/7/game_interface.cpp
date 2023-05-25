#include <iostream>
#include "game_interface.hpp"

//*******************************************

void game_interface::display(game_state::board game)
{
    char row[3] = {'a', 'b', 'c'};
    int move;

    std::cout<< "   _1___2___3_\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout<< row[i];
        for (int j = 0; j < 3; j++)
        {
            move = 3*i + j;
            std::cout<< " | " << game.get_board_box(move);
        }
        std::cout<< " |\n";
    }
    std::cout<< "  -------------\n\n";
}

//*******************************************

int game_interface::ask_player_for_move()
{
    char row[3] = {'a', 'b', 'c'};

    std::cout<< "Make your move - give number of box you want to mark in this move\n\n";
    std::cout<< "   _1___2___3_\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout<< row[i];
        for (int j = 0; j < 3; j++)
        {
            std::cout<< " | " << type_of_moves[i][j];
        }
        std::cout<< " |\n";
    }
    std::cout<< "  -------------\n\n";

    int move;
    std::cin>> move;
    while (move >= 9 || move < 0)
    {
        std::cout<< "Move out of range. Give another number\n";
        std::cin>> move;
    }

    return move;
}

//*******************************************

void game_interface::computer_move()
{
    std::cout<< "Computer makes move...\n\n";
}

//*******************************************

bool game_interface::end_game(game_state::board game)
{ 
    int winner = game_state::someone_won(game);
    if (winner == 1)
    {
        std::cout<< "You won! Congratulations!";
        return true;
    }
    else if (winner == 2)
    {
        std::cout<< "You lost! :c";
        return true;
    }

    if (game_state::no_moves(game))
    {
        std::cout<< "No more moves.\nGAME OVER";
        return true;
    }

    return false;
}

//*******************************************