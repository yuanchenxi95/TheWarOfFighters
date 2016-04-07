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
Controller::Controller(IFighter* fighter) {
    this->fighter = fighter;
}

void Controller::handleKeys(){
    char ch = getch();
    switch (ch) {
        case KEY_LEFT:
            this->fighter->moveLEFT;
            break;
            
        case KEY_RIGHT:
            this->fighter->moveRight;
            break;
            
        case KEY_UP:
            this->fighter->moveUp;
            break;
        case KEY_DOWN:
            this->fighter->moveDown;
            break;
        case  ' ':
            this->fighter->shoot;
        default:
            break;
    }
}
Controller::~Controller(){
    
}

