//
//  Controller.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "Controller.hpp"
#include <ncurses.h>

Controller::Controller() {
    this->iwom = new IWOFModel(15, 35);
    this->adapter = new Adapter(iwom);
    this->vm = adapter->ModelToViewModel(iwom);
    time(&this->startTime);
    this->curTime = this->startTime;
    this->view = new TerminalView(vm);
    this->view->initialize();
}

void Controller::handleKeys(){
    int ch = getch();
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
        case 'Q':
            this->iwom->setGameState(QUIT);
            break;
        default:
            break;
    }
}

Controller::~Controller(){
    delete this->iwom;
}
void Controller::welcome() {
    this->view->welcome();
    int ch = getch();
    if(ch == 'Q' or ch == 'q') {
        this->iwom->setGameState(QUIT);

    }
    this->startLoop();
}
void Controller::startLoop() {
    clear();
    while(this->iwom->getGameState() != QUIT) {
        
        switch (this->iwom->getGameState()) {
            case PLAYING:
                this->handleKeys();
                time(&curTime2);
                if (curTime2 - curTime >= 1) {
                    this->iwom->tick();
                    this->adapter = new Adapter(iwom);
                    this->vm = adapter->ModelToViewModel(iwom);
                    this->view->render();
                }
                curTime = curTime2;

                break;
            case GAMEMOVER:
                this->iwom->setGameState(GAMEMOVER);
                this->adapter = new Adapter(iwom);
                this->vm = adapter->ModelToViewModel(iwom);
                this->view->render();
                // TO-DO
                // add game over text to the view.
                break;
            default:
                break;
        }
    }
    this->view->endGame();
    getch();
    delete(this->view);
    delete(this->iwom);
    delete (this->adapter);

}
