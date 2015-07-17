//
//  Game.h
//  NoughtsAndCrosses
//


#ifndef __NoughtsAndCrosses__Game__
#define __NoughtsAndCrosses__Game__

#include <cstdio>
#include "Board.h"
#include "Player.h"

class game{
    //----- members -----
    public:
    bool is_over;
    
    _board board;
    player p1;
    player p2;
    
    //------ Fns ------
    void init();
    void win(player winner);
    void draw();
    
private:
    void display_winner(player winner);
    void show_welcome_msg();
    
};






#endif /* defined(__NoughtsAndCrosses__Game__) */
