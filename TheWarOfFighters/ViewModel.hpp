//
//  ViewModel.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef ViewModel_hpp
#define ViewModel_hpp
#include "Cell.hpp"
#include <stdio.h>
#include <vector>
class ViewModel {
private:
    int row_size;
    int col_size;
    Cell* player_pos;
    std::vector<Cell*> * enemy_pos;
    std::vector<Cell*> * projectilePos;
    

public:
    ViewModel(int row_size, int col_size, Cell* player_pos,
              std::vector<Cell*> * enemy_pos, std::vector<Cell*> * projectilePos);
    ~ViewModel();
    int get_row_size();
    int get_col_size();
    Cell* get_player_pos();
    std::vector<Cell*> *get_enemy_pos();
    std::vector<Cell*> * getProjectilePos();
};
#endif /* ViewModel_hpp */
