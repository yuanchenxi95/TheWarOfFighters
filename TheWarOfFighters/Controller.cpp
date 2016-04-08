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
}

void Controller::handleKeys(){
    char ch = getch();
    switch (ch) {
        case KEY_LEFT:
            this->iwom->moveLeft();
            break;
        case KEY_RIGHT:
            this->iwom->moveRight();
            break;
        case KEY_UP:
            this->iwom->moveUp();
            break;
        case KEY_DOWN:
            this->iwom->moveDown();
            break;
        case ' ':
            this->iwom->shoot();
            break;
        default:
            break;
    }
}

Controller::~Controller(){
    delete this->iwom;
}

