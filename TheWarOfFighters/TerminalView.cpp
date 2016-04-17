//
//  TerminalView.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "TerminalView.hpp"
#include <ncurses.h>
#include "ViewModel.hpp"
TerminalView::TerminalView(ViewModel* vm) {
    this->vm = vm;
    this->update();

    //TODO update
    

}

TerminalView::~TerminalView() {
}

void TerminalView::clear() {
    ::clear();
}

void TerminalView::initialize() {
    // Initialize ncurses status
    clear();
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}


void TerminalView::welcome(){
    printw ("Welcome to the War of Figher game!\n Press any key to start.\npress q or Q to quit.\n");
}


void TerminalView::endGame() {
    printw("the game has quit\n");
    endwin();
}


void TerminalView::createMap() {
    mvaddch(this->player_pos->getX(), this->player_pos->getY(), this->figher_char);
    
    // todo : mapaddch all enemies and projectiles
}

void TerminalView::render() {
    this->update();
    mvaddch(this->player_pos->getX(), this->player_pos->getY(), this->figher_char);
    printw("(%d,%d)\n", this->player_pos->getX(), this->player_pos->getY());
    
//    printw("Hi%d\n", enemy_pos->size());
    for(int i = 0; i < enemy_pos->size(); i++) {
        mvaddch(this->enemy_pos->at(i)->getX(),this->enemy_pos->at(i)->getY(),this->enemy_char);
        
//        printw("enemy[%d]: (%d, %d)\n", i, this->enemy_pos->at(i)->getX(), this->enemy_pos->at(i)->getY());
//        printw("%p\n", enemy_pos->at(i));
    }

//    for (int i = 0; i < projectilePos->size(); i++) {
//        mvaddch(this->projectilePos->at(i)->getX(), this->projectilePos->at(i)->getX(), this->bullet_char);
//    }
}

void TerminalView::update() {
    this->col_size = vm->get_col_size();
    this->row_size = vm->get_row_size();
    this->player_pos = vm->get_player_pos();
    this-> enemy_pos = vm->get_enemy_pos();
    this-> projectilePos = vm->getProjectilePos();
}

