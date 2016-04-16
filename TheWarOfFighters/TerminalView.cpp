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
#include <ncurses.h>
TerminalView::TerminalView(ViewModel* vm) {
    this->vm = vm;
    this->col_size = vm->get_col_size();
    this->row_size = vm->get_row_size();
    this->player_pos = vm->get_player_pos();
    this-> enemy_pos = vm->get_enemy_pos();
    this-> projectilePos = vm->getProjectilePos();
    
    //initialize ncurses status
    clear();
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

}

TerminalView::~TerminalView() {
}

void TerminalView::clear() {
    clear();
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
    endwin();
}


void TerminalView::createMap() {
    mvaddch(this->player_pos->getX(), this->player_pos->getY(), this->figher_char);
    
    // todo : mapaddch all enemies and projectiles
}

void TerminalView::render() {
    mvaddch(this->player_pos->getX(), this->player_pos->getY(), this->figher_char);
    for(int i = 0; i < sizeof(enemy_pos); i++) {
        mvaddch(this->enemy_pos->at(i)->getX(),this->enemy_pos->at(i)->getY(),this->enemy_char);
    }
    
    for (int i = 0; i < sizeof(projectilePos); i++) {
        mvaddch(this->projectilePos->at(i)->getX(), this->projectilePos->at(i)->getX(), this->bullet_char);
    }
}
