//
//  Player.h
//  NoughtsAndCrosses
//
//  Created by Patrick Mintram on 17/07/2015.
//  Copyright (c) 2015 Patrick Mintram. All rights reserved.
//

#ifndef __NoughtsAndCrosses__Player__
#define __NoughtsAndCrosses__Player__

#include <cstdio>
#include <cassert>
#include <string>
#include <cstdlib>

#define MAX_NAME_LEN    20

class player{
    //------ members ------
   public:
    char *name;
    char symbol;
    struct _input{
        int col, row;
    };
    struct _input input;

    //----- Fns -------

    void init(char* name, char counter);
    void destroy();
    void get_input();
};

#endif /* defined(__NoughtsAndCrosses__Player__) */
