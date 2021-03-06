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
    this->vm = new ViewModel();
    this->adapter = new Adapter(iwom, vm);
    adapter->ModelToViewModel();
    this->startTime = std::chrono::high_resolution_clock::now();
    this->curTime = this->startTime;
    this->view = new TerminalView(vm);
    this->view->initialize();
}

void Controller::handleKeys(){
    int ch = getch();

    switch (ch) {
        case KEY_LEFT:
            this->iwom->moveLeft();
//            printw("%d,%d\n",this->iwom->getPlayerFighter()->getPosition()->getX(), this->iwom->getPlayerFighter()->getPosition()->getY());
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
        case 'q':
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
    this->view->setNoDelay();
    this->startLoop();
}
void Controller::startLoop() {
    
    clear();
    // the duration of the time
    std::chrono::duration<double> time_span;
    
    while(this->iwom->getGameState() != QUIT && this->iwom->getGameState() != GAMEMOVER) {
        
        switch (this->iwom->getGameState()) {
            case PLAYING:
                curTime2 = std::chrono::high_resolution_clock::now();
                
                
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(curTime2 - curTime);
                if (time_span.count() >= 0.1) {
                
                    this->handleKeys();
                    this->iwom->tick();
                    adapter->ModelToViewModel();
                    this->view->render();
                    curTime = curTime2;
                }

                break;
            case GAMEMOVER:
                this->iwom->setGameState(GAMEMOVER);
                adapter->ModelToViewModel();
                this->view->render();
                break;
            default:
                break;
        }
    }
    if(this->iwom->getGameState() == QUIT) {
        this->view->endGame();
    } else {
        this->view->gameOver();
    }
    delete(this->view);
    delete(this->iwom);
    delete (this->adapter);

}
