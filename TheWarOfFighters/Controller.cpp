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
    this->view = new View(this->iwom);
    time(&this->startTime);
    this->curTime = this->startTime;
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

void Controller::startLoop() {
    while(this->iwom->getGameState() != QUIT) {
        switch (this->iwom->getGameState()) {
            case PLAYING:
                time(&curTime2);
                if (curTime2 - curTime >= 1) {
                    this->iwom->tick();
                    this->view->render();
                    
                }
                curTime = curTime2;

                break;
            case GAMEMOVER:
                // TO-DO
                // add game over text to the view.
                break;
            default:
                break;
        }
    }
}
