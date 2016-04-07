//
//  Controller.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "Controller.hpp"
#include "IProjectile.hpp"
#include <ncurses.h>
Controller::Controller(IProjectile* projectile) {
    this->projectile = projectile;
}

void Controller::handleKeys(){
    char ch = getch();
    switch (ch) {
        case KEY_LEFT:
            this->projectile->moveLEFT;
            break;
            
        case KEY_RIGHT:
            this->projectile->moveRight;
            break;
            
        case KEY_UP:
            this->projectile->moveUp;
            break;
        case KEY_DOWN:
            this->projectile->moveDown;
            break;
        case ' '：
            this->projectile->shoot;
        default:
            break;
    }
}
Controller::~Controller(){
    
}

