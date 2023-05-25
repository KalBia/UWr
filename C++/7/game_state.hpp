#ifndef game_state_h
#define game_state_h

//*******************************************

namespace game_state 
{
    class board
    {
        char tab[3][3];
        bool who_plays_now;

    public:
        board();
        void update_board(int move);
        char get_board_box(int move);
        bool get_who();
    };

    int someone_won(board);
    bool no_moves(board);
}

//*******************************************

#endif