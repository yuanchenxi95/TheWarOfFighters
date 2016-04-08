//
//  FightersManager.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "FightersManager.hpp"


FightersManager::FightersManager(ProjectileManager * p, Map * map) {
    this->pm = p;
    this->map = map;
    
    vector<EnemyFighter*> * loe;
    this->initializeEnemyList(loe);
    this->wave = new Wave(loe);
    Cell * playerCell = this->map->getMap()->at(map->height / 2)->at(0);
    this->player = new PlayerFighter(playerCell, 100, RIGHT);
}

FightersManager::~FightersManager() {
    delete this->wave;
    delete this->player;
}

// tick the world and return the number of dead enemies
int FightersManager::tick() {
    
    
    int count = this->wave->move();
    this->addProjectile();
    this->shoot();
    
    this->pm->tickLop();
    // to-do damage the fighters
    
    if (this->wave->allEnemiesDead()) {
        vector<EnemyFighter*> * loe;
        this->initializeEnemyList(loe);
        this->wave = new Wave(loe);
    }
    return count;
}

void FightersManager::addProjectile() {
    for (EnemyFighter * f : *this->wave->getEnemies()) {
        this->pm->addProj(new IProjectile(f->getPosition(), f->getDamage(),  ENEMYPORJECTILE, f->getDirection()));
    }
}

void FightersManager::shoot() {
    this->pm->addProj(new IProjectile(this->player->getPosition(),
                                      this->player->getDamage(),
                                      PLAYERPROJECTILE,
                                      this->player->getDirection()));
}

// initialize 5 enemies
void FightersManager::initializeEnemyList(vector<EnemyFighter*> * loe) {
    loe  = new vector<EnemyFighter*>();
    
    int i;
    
    
    vector<Cell*> * voc = this->map->getRightMostCells();
    
    for (i = 0; i < 5; i++) {
        // to do
        int r = rand() % voc->size();
        
        loe->push_back(new EnemyFighter(voc->at(r), 20, LEFT));
        
        
        voc->erase(voc->begin() + r);
    }
}

ProjectileManager * FightersManager::getProjectileManager() {
    return this->pm;
}
vector<EnemyFighter*> * FightersManager::getEnemyFighters() {
    return this->wave->getEnemies();
}

Map * FightersManager::getMap() {
    return this->map;
}
PlayerFighter * FightersManager::getPlayerFighter() {
    return this->player;
}

