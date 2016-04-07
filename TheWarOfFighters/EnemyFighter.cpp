//
//  EnemyFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "EnemyFighter.hpp"

EnemyFighter::EnemyFighter(Cell * c, int health, Direction d) : IFighter(c, health, d) {
    
}

EnemyFighter::~EnemyFighter() {
    
}

FighterType EnemyFighter::getFigterType() {
    return ENEMYFIGHTER;
}


