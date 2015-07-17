//
//  Player.cpp
//  NoughtsAndCrosses
//

#include "Player.h"

void player::init(char *player_name, char player_symbol){
    
    //get memory for the name string
    name = (char*)calloc(MAX_NAME_LEN, sizeof(char));
    assert(name);
    
    //put it in the memory space
    strcpy(name, player_name);
    
    //init inputs to 0
    input.row = input.col = 0;
    symbol = player_symbol;
    
}

//free up name string
void player::destroy(){
    if (name) {
        free(name);
        name = nullptr;
    }
}

void player::get_input(){

    int in = 0;
    printf("\n%s, enter a column: ", name);
    scanf("%d", &in);
    
    input.row = in - 1;
    
    printf("Enter a row: ");
    scanf("%d", &in);
    
    input.col = in - 1;
    
}