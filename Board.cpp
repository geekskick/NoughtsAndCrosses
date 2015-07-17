//
//  Board.cpp
//  NoughtsAndCrosses
//

#include "Board.h"

void _board::init(char filler){
    
    //init to spaces in the _board
    for (int i = 0; i < BOARD_HEIGHT; ++i){
        for (int j = 0; j < BOARD_WIDTH; ++j){
            board_layout[i][j] = filler;
        }
    }
    
    blank_symbol = filler;
    
}

void _board::show(){
    
    /*
     
     show this, but for the correct size of board
     
     Col:           1 	2 	3
     Row: 1 		[O]	[O]	[O]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[X]
     
     
     */
    
    printf("\nCol: \t");
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        printf("\t%d ", i + 1);
    }
    
    for (int i = 0; i < BOARD_HEIGHT; ++i){
        printf("\nRow: %d \t", i + 1);
        for (int j = 0; j < BOARD_WIDTH; ++j){
            printf("\t[%c]", board_layout[i][j]);
        }
    }
    
}

bool _board::space_is_taken(_input input){
    
    if (board_layout[input.row][input.col] != blank_symbol) {
        return true;
    }
    return false;
    
}

//boundary checking
bool _board::input_is_on_board(_input input){
    
    if (input.col < 0 || input.col >= BOARD_WIDTH) {
        return false;
    }
    
    if (input.row < 0 || input.row >= BOARD_HEIGHT) {
        return false;
    }
    
    return true;
}

//boundary checking
bool _board::input_is_on_board(int y, int z){
    
    if (z < 0 || z >= BOARD_WIDTH) {
        return false;
    }
    
    if (y < 0 || y >= BOARD_HEIGHT) {
        return false;
    }
    
    return true;
}

void _board::make_move(int col, int row, char symbol){
    
    //passing to other functions is easier is it's a struct
    _input input = {
        .col = col,
        .row = row
    };
    
    //incase input isn't checked before being passed in
    if (input_is_on_board(input) && !space_is_taken(input)){
        board_layout[input.row][input.col] = symbol;
    }
    else printf("Not a valid move! You miss a go!\n");
}

//show the contents of the one square
void _board::show_space(int row, int col){
    printf("[%d][%d] = %c\n", row, col, board_layout[row][col]);
}

bool _board::check_left_diags(){

    /*
     
     check the lef sloping diagonals, as follows
     
     Col:           1 	2 	3
     Row: 1 		[m]	[ ]	[ ]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[ ]
     Row: 2 		[ ]	[m]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[ ]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[m]
     Col:           1 	2 	3
     Row: 1 		[O]	[m]	[ ]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[ ]
     Row: 2 		[ ]	[ ]	[m]
     Row: 3 		[ ]	[ ]	[ ]

     if a square isn't a BLANK character ' ' then compare it to the
     one in the next position, if that's a match compare to the one in the NEXT position to that
     
     */
    int y, z;

    //check diagonals starting from the top left square, working right
    for(int i = 0; i < BOARD_WIDTH; i++){
        
        for(y = 0, z = i; input_is_on_board(y,z); y++, z++){
            
            if (board_layout[y][z] != blank_symbol && board_layout[y + 1][z + 1] == board_layout[y][z]) {
                
                if (board_layout[y][z] == board_layout[y + 2][z + 2]) {
                    return true;
                }
            }
        }
    }
    
    //make sure the bottom left corner is taken care of
    for(int i = 1; i < BOARD_HEIGHT; i++){
        
        for(y = i, z = 0; input_is_on_board(y,z); z++, y++){
    
            if (board_layout[y][z] != blank_symbol && board_layout[y+1][z+1] == board_layout[y][z]) {
                
                if (board_layout[y][z] == board_layout[y+2][z+2]) {
                    return true;
                }
                
            }
        }
    }
    
    return false;
    
}

bool _board::check_cols(){
    //checks each colunm for matches of three
    
    for (int j = 0; j < BOARD_WIDTH; ++j) {
        
        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            
            if (board_layout[j][i] == board_layout[j + 1][i] && board_layout[j][i] != blank_symbol) {
                
                if (board_layout[j + 2][i] == board_layout[j][i]) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool _board::check_rows(){

    //checks each row
    for (int j = 0; j < BOARD_HEIGHT; ++j) {
        
        for (int i = 0; i < BOARD_WIDTH; ++i) {
                        if (board_layout[j][i] == board_layout[j][i + 1] && board_layout[j][i] != blank_symbol) {
                
                if (board_layout[j][i + 2] == board_layout[j][i]) {
                    return true;
                }
            }
        }
    }
    return false;
}

void _board::save_char(int y, int z){
    temp_symbol = board_layout[y][z];
}

char _board::get_char(){
    return temp_symbol;
}

//temporarility replace the grid location with an 'm' and printf the grid, hen put the original char back in
void _board::show_checked(int y, int z){
    save_char(y, z);
    board_layout[y][z] = 'm';
    show();
    board_layout[y][z] = get_char();
}

bool _board::check_right_diags(){
    /*
     checks through thr grid as follows, where 'm' is the square being checked,
     and 'l' is the start point
     
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[m]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     
     [1][1]
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[l]
     Row: 2 		[ ]	[m]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     
     [2][0]
     Col:           1 	2 	3
     Row: 1 		[O]	[ ]	[l]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[m]	[ ]	[ ]
     
     [0][1]
     Col: 		     1 	2 	3
     Row: 1 		[O]	[m]	[l]
     Row: 2 		[ ]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     
     [1][0]
     Col: 		    1 	2 	3
     Row: 1 		[O]	[ ]	[l]
     Row: 2 		[m]	[ ]	[ ]
     Row: 3 		[ ]	[ ]	[ ]
     

     [1][2]
     Col: 		    1 	2 	3
     Row: 1 		[O]	[ ]	[l]
     Row: 2 		[ ]	[ ]	[m]
     Row: 3 		[ ]	[ ]	[ ]
     
     if a square isn't a BLANK character ' ' then compare it to the 
     one in the next position, if that's a match compare to the one in the NEXT position to that
     
     */
    
    int y, z;

    //-1 to account for 0 indexing
    for(int i = BOARD_WIDTH - 1; i > 0; --i){
        
        //do this, while the row is still valid, and the column is greate than of equal to one,
        //aka it's a valid square
        for(y = 0, z = i; input_is_on_board(y, z); y++, z--){
            
            if (board_layout[y][z] != blank_symbol && board_layout[y + 1][z - 1] == board_layout[y][z]) {
                
                if (board_layout[y][z] == board_layout[y + 2][z - 2]) {
                    return true;
                }
            }
        }
    }
    
    for(int i = 1; i < BOARD_HEIGHT; ++i){
    
        for(y = i, z = BOARD_WIDTH - 1; input_is_on_board(y, z); y++, z--){
         
            if (board_layout[y][z] != blank_symbol && board_layout[y + 1][z - 1] == board_layout[y][z]) {
                
                if (board_layout[y][z] == board_layout[y + 2][z - 2]) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool _board::winning_move(){
    if(check_cols())        {   return true;    }
    if(check_left_diags())  {   return true;    }
    if(check_right_diags()) {   return true;    }
    if(check_rows ())       {   return true;    }
    return false;
}

bool _board::is_full(){
    
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if(board_layout[i][j] == blank_symbol) { return false; }
        }
    }
    
    return true;
}



