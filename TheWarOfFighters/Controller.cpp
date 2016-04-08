//
//  Controller.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "Controller.hpp"
#include "PlayerFighter.hpp"
#include <ncurses.h>

Controller::Controller() {
    this->iwom = new IWOFModel(15, 35);
    this->fighter = iwom->getPlayerFighter();
}

void Controller::handleKeys(){
    char ch = getch();
    switch (ch) {
        case KEY_LEFT:
            this->fighter->moveLeft();
            break;
            
        case KEY_RIGHT:
            this->fighter->moveRight();
            break;
            
        case KEY_UP:
            this->fighter->moveUp();
            break;
        case KEY_DOWN:
            this->fighter->moveDown();
            break;
        default:
            break;
    }
}
Controller::~Controller(){
    
}

