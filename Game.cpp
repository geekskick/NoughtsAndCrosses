//
//  Game.cpp
//  NoughtsAndCrosses
//


#include "Game.h"
#include "NoughtsAndCrosses.h"

void game::init(){
    is_over = false;
    //user_input.col = user_input.row = 0;

    show_welcome_msg();
    
    //initialise board to blank character
    board.init(BLANK);
    
    //get user name and put in temporary variable
    char name_temp[MAX_NAME_LEN];
    
    printf("Player 1 name <%c>: ", NOUGHT);
    scanf("%s", name_temp);
    
    p1.init(name_temp, NOUGHT);
    
    //fill temp_name with 0s to overwrite it all
    memset(name_temp, 0, sizeof(name_temp)/sizeof(name_temp[0]));
    
    printf("Player 2 name <%c>: ", CROSS);
    scanf("%s",name_temp);
    
    p2.init(name_temp, CROSS);
}

void game::show_welcome_msg(){
    printf("Welcome to noughts and crosses!\n"                          );
    printf("The aim of the game is to get three of\n"                   );
    printf("your symbol in a row, player 1 is shown by a %c\n"          , NOUGHT );
    printf("while player 2 is shown by a %c.\n"                         , CROSS );
    printf("Please enter the player names,\n"                           );
}

void game::win(player winner){
    display_winner(winner);
    p1.destroy();
    p2.destroy();
    is_over = true;
}

void game::draw(){
    p1.destroy();
    p2.destroy();
    is_over = true;
}

void game::display_winner(player winner){
    printf("\n**************************************\n");
    printf("* Contratulations %s, you WON!\n", winner.name);
    printf("**************************************\n");
    board.show();
}