//
//  Controller.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp
#include <ncurses.h>
#include <stdio.h>
#include "PlayerFighter.hpp"
class Controller {
public:
    Controller(PlayerFighter* fighter);
    ~Controller();
    void handleKeys();
protected:
    PlayerFighter* fighter;
};
#endif /* Controller_hpp */
