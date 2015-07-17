//
//  main.cpp
//  NoughtsAndCrosses
//

#include "NoughtsAndCrosses.h"


int main(int argc, const char * argv[]) {
    
    game g;
    
    g.init();
    
    player *active_player = nullptr;
    
    int turn_counter = rand() % 1;
    
    while(!g.is_over){
        
        g.board.show();
        
        //change over the active player so that the different one plays each time
        if(turn_counter++ % 2 == 0){
            active_player = &g.p1;
        }
        else{
            active_player = &g.p2;
        }
        
        active_player->get_input();
        
        g.board.make_move(active_player->input.row, active_player->input.col, active_player->symbol);
        
        if(g.board.winning_move()) {
            g.win(*active_player);
        }
        
        if (g.board.is_full()) {
            printf("No more room\n");
            g.draw();
        }

    }

    return 0;
}
