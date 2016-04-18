//
//  FightersManager.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "FightersManager.hpp"
#include <ncurses.h>

FightersManager::FightersManager(ProjectileManager * p, Map * map) {
    this->pm = p;
    this->map = map;
    
    vector<EnemyFighter*> * loe;
    this->initializeEnemyList(&loe);

    this->wave = new Wave(loe);
    Cell * playerCell = this->map->getMap()->at(map->height / 2)->at(0);
    this->player = new PlayerFighter(playerCell, 16, RIGHT);
}

FightersManager::~FightersManager() {
    delete this->wave;
    delete this->player;
}

// tick the world and return the number of dead enemies
int FightersManager::tick() {
    
    
    int count = this->wave->move();
    this->addProjectile();
//    this->shoot();
    
    this->pm->tickLop();
    // to-do damage the fighters
    this->hitFighter();
    
    if (this->wave->allEnemiesDead()) {
        vector<EnemyFighter*> * loe;
        this->initializeEnemyList(&loe);
        this->wave = new Wave(loe);
    }
    return count;
}

void FightersManager::hitFighter() {
    vector<IProjectile*> * vop = this->pm->getLop();
    vector<EnemyFighter *> * voef = this->getEnemyFighters();
    PlayerFighter * pf = this->getPlayerFighter();
    
    for (IProjectile * p : * vop) {
        Cell * playPos = pf->getPosition();
        Cell * pp = p->getPosition();

        if (p->getProjectileType() == ENEMYPORJECTILE) {
            
            if (playPos->getY() == pp->getY() && playPos->getX() == pp->getX()) {
                p->setProjectileType(ZOMBIEPROJECTILE);
                pf->damageThisFighter(p->getDamage());
            }
        } else if(p->getProjectileType() == PLAYERPROJECTILE) {
            for (EnemyFighter * ef : *voef) {
                Cell * pe = ef->getPosition();
                
                if (pe->getY() == pp->getY() && pe->getX() == pp->getX()) {
                    p->setProjectileType(ZOMBIEPROJECTILE);
                    ef->damageThisFighter(p->getDamage());
                }
                
                
                
            }
        }
        
        
    }
    
    for (EnemyFighter * ef : *voef) {
        Cell * pe = ef->getPosition();
        Cell * playPos = pf->getPosition();

        if (playPos->getX() == pe->getX() && playPos->getY() == pe->getY()) {
            pf->damageThisFighter(1);
            ef->setEnemyType(DEADENEMYFIGHTER);
        }
        
        
    }
    
    
}

void FightersManager::addProjectile() {
    int randPoj = rand()%5;
    int randEnemy = rand()%(this->wave->getEnemies()->size()+1);
    for (int i = 0; i <this->wave->getEnemies()->size();i++) {
        if(randPoj  == 0 && i == randEnemy) {
            EnemyFighter *ef = this->wave->getEnemies()->at(i);
        this->pm->addProj(new IProjectile(ef->getPosition(), ef->getDamage(),  ENEMYPORJECTILE, ef->getDirection()));
        }
    }
}

void FightersManager::shoot() {
    this->pm->addProj(new IProjectile(this->player->getPosition(),
                                      this->player->getDamage(),
                                      PLAYERPROJECTILE,
                                      this->player->getDirection()));
}



// initialize 5 enemies
void FightersManager::initializeEnemyList(vector<EnemyFighter*> ** loe) {
    *loe  = new vector<EnemyFighter*>();
    
    int i;
    

    vector<vector<Cell*>*> * curMap = this->map->getMap();
    
    for (i = 0; i < 5; i++) {
        // to do
        //int r = rand() % voc->size();
        int rX = (rand() %(curMap->at(0)->size()/2))+(curMap->at(0)->size()/2);
        int rY = rand() % (curMap->size());
        (*loe)->push_back(new EnemyFighter(curMap->at(rY)->at(rX), 1, LEFT));
        
        
        //curMap->erase(curMap->begin()+(rY*curMap->size()+rY));
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


