//
//  ViewModel.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "ViewModel.hpp"
#include <vector>
#include "Cell.hpp"
ViewModel::ViewModel() {
    
}
int ViewModel::get_row_size() {
    return this->row_size;
}

int ViewModel::get_col_size() {
    return this->col_size;
}

Cell* ViewModel::get_player_pos() {
    return this->player_pos;
}

std::vector<Cell*> * ViewModel::get_enemy_pos() {
    return this->enemy_pos;
}

std::vector<Cell*> * ViewModel::getProjectilePos() {
    return this->projectilePos;
}
int ViewModel::getScore() {
    return this->score;
}

int ViewModel::getHP() {
    return this->hp;
}
ViewModel::~ViewModel() {
    
}

void ViewModel::update(int row_size, int col_size, Cell* player_pos,
                       std::vector<Cell*> * enemy_pos, std::vector<Cell*> * projectilePos, GameState gs, int score, int hp) {
    this->row_size = row_size;
    this->col_size = col_size;
    this->player_pos = player_pos;
    this->enemy_pos = enemy_pos;
    this->projectilePos = projectilePos;
    this->gs = gs;
    this->score = score;
    this->hp = hp;
}