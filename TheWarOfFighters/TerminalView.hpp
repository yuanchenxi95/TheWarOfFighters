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
    ~TerminalView();
    void welcome();///
    void initialize();///
    void endGame();///
    void clear();///
    void createMap();//?
    void createFighter();
    void render();//?
    void update();
    void setNoDelay();
    int count = 0;
    void gameOver();
};
#endif /* TerminalView_hpp */
