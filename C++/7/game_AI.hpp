#ifndef game_AI_h
#define game_AI_h
#include "game_state.hpp"

//*******************************************

namespace game_AI
{
    bool is_good_move(int, game_state::board);
    int make_move(game_state::board);
}

//*******************************************

#endif