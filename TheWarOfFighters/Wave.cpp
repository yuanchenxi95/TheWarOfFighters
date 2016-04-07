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
    // TO-DO
}

// are all the enemies dead
bool Wave::allEnemiesDead() {
    for (EnemyFighter* f: *this->lof) {
        if (!f->isDead()) {
            return false;
        }
    }
    
    return true;
    
}

// get the enemy list
vector<EnemyFighter *> * getEnemies();

// move and spawn the enemy, return how many enemies reach the end
int move();



