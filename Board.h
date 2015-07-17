//
//  Board.h
//  NoughtsAndCrosses
//


#ifndef NoughtsAndCrosses_Board_h
#define NoughtsAndCrosses_Board_h

#include <cstdio>

class _board{
    
#ifndef _BOARD_WIDTH
#define BOARD_WIDTH     3
#endif
    
#ifndef _BOARD_HEIGHT
#define BOARD_HEIGHT    3
#endif
    
    
public:
    //----- members -----
    char board_layout[BOARD_HEIGHT][BOARD_WIDTH];
    
    //----- Fns -------
    void show();
    void init(char filler);
    void make_move(int col, int row, char symbol);
    bool winning_move();
    bool is_full();
    
private:
    
    struct _input {
        int col, row;
    };
    
    char temp_symbol;
    char blank_symbol;
    
    bool check_cols();
    bool check_rows();
    bool check_left_diags();
    bool check_right_diags();
    bool input_is_on_board(_input input);
    bool input_is_on_board(int y, int z);
    bool space_is_taken(_input input);
    
    //for debugging
    void show_space(int row, int col);
    void save_char(int row, int col);
    char get_char();
    void show_checked(int y, int z);
    
};

#endif
