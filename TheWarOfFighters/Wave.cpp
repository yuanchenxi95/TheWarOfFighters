//
//  Wave.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "Wave.hpp"


Wave::Wave(vector<EnemyFighter*>* lof) {
    this->lof = lof;
    //spawn every minion in 100 milliseconds
    this->spawnCounter = new Counter(new int(100));
}

Wave::~Wave() {
    this->lof->clear();
    delete(this->lof);
    delete(this->spawnCounter);
}

// tick and move the wave.
void Wave::tick() {
    spawnCounter->tick();
}

// return ture if there is an enemy to be spawned
bool Wave::anyEnemyToSpawn() {
    return false;
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
vector<EnemyFighter *> * Wave::getEnemies() {
    return this->lof;
}

// move and spawn the enemy, return how many enemies were killed in this wave
int Wave::move() {
    // TO-DO
    int count = 0;
    
    this->updateList();
    
    
    for (EnemyFighter * f : *this->lof) {
        if (f->getEnemyType() == ALIVEENEMYFIGHTER) {
            f->moveThisFighter();
        } else if (f->getEnemyType() == DEADENEMYFIGHTER){
            count++;
        }
    }
    
    return count;
    
    
}



