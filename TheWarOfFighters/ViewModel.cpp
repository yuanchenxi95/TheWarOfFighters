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
ViewModel::ViewModel(int row_size, int col_size, Cell* player_pos,
                     std::vector<Cell*> enemy_pos) {
    this->row_size = row_size;
    this->col_size = col_size;
    this->player_pos = player_pos;
    this->enemy_pos = enemy_pos;
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

std::vector<Cell*> ViewModel::get_enemy_pos() {
    return this->enemy_pos;
}

ViewModel::~ViewModel() {
    
}