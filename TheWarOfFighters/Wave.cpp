//
//  Wave.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "Wave.hpp"


Wave::Wave(std::vector<EnemyFighter*>* lof) {
    
    
    
    this->lof = lof;}

Wave::~Wave() {
    this->lof->clear();
    delete(this->lof);
}
// update enemy list, remove the dead enemies
void Wave::updateList() {
    for (EnemyFighter * f : *this->lof) {
        f->updateFighter();
    }
}

// are all the enemies dead
bool Wave::allEnemiesDead() {
    for (EnemyFighter* f: *this->lof) {
        if (f->getEnemyType() != DEADENEMYFIGHTER && f->getEnemyType() != ZOMBIEENEMYFIGHTER) {
            return false;
        }
    }
    
    return true;
    
}

// get the enemy list
std::vector<EnemyFighter *> * Wave::getEnemies() {
    
    return this->lof;
}

// move and spawn the enemy, return how many enemies were killed in this wave
int Wave::move() {

    this->updateList();
    
    
    for (EnemyFighter * f : *this->lof) {
        if (f->getEnemyType() == ALIVEENEMYFIGHTER) {
            f->moveThisFighter();
        }
    }
    
    return removeBadEnemy();
    
    
}

int Wave::removeBadEnemy() {
    int count = 0;
    
    std::vector<EnemyFighter*>* newLof = new std::vector<EnemyFighter*>();

    
    for (EnemyFighter * f : *this->lof) {
        if (f->getEnemyType() == ALIVEENEMYFIGHTER) {
            newLof->push_back(f);
        } else if (f->getEnemyType() == DEADENEMYFIGHTER) {
            count++;
        }
    }
    
    lof->clear();
    lof = newLof;
    
    return count;

    
}



