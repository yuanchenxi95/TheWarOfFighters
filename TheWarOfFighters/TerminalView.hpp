//
//  TerminalView.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef TerminalView_hpp
#define TerminalView_hpp
#include <ncurses.h>
#include <stdio.h>
#include "ViewModel.hpp"

class TerminalView {
protected:
    ~TerminalView();
    char figher_char ='>';
    char bullet_char = '-';
    char enemy_char='*';
    int row_size;
    int col_size;
    Cell* player_pos;
    std::vector<Cell*> * enemy_pos;
    std::vector<Cell*> * projectilePos;
public:
    ViewModel* vm;
    TerminalView(ViewModel* vm);
    void welcome();
    void initialize();
    void endGame();
    void clear();
    void createMap();
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();
    void moveFighter();
    void createFighter();
    //todo
    // generate player projectile
    // move player projectile
    // generate enemy projectile
    // move enemy projectile
    // lost title
    // beginning title
    // win title
    // round title
    // fighter destroied
    //
};
#endif /* TerminalView_hpp */
