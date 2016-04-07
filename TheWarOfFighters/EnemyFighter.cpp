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



// set the enemy fighter type
EnemyFighterType EnemyFighter::setEnemyType(EnemyFighterType eft) {
    this->eft = eft;
    return eft;
}

// get the enemy fighter type
EnemyFighterType EnemyFighter::getEnemyType() {
    return this->eft;
}

int EnemyFighter::getDamage(int d) {
    this->health -= d;
    if (this->health <= 0) {
        this->eft = DEADENEMYFIGHTER;
    }
    return this->health;
}

