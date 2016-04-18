//
//  Adapter.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/13/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#include "Adapter.hpp"
#include <vector>
#include <iostream>
Adapter::Adapter(IWOFModel* adaptee, ViewModel* vm) {
    this->adaptee = adaptee;
    this->vm = vm;
}

Adapter::~Adapter(){
    
}

void Adapter::ModelToViewModel() {
    int row_size = adaptee->getBoard()->at(0)->size();
    int col_size = adaptee->getBoard()->size();
    int score = adaptee->getScore();
    int hp = adaptee->getPlayerFighter()->getHealth();
    GameState gs = adaptee->getGameState();
    Cell* playerFighterPos = adaptee->getPlayerFighter()->getPosition();
    std::vector<EnemyFighter*> * enemyList = adaptee->getEnemyFighterList();
    std::vector<Cell*> * enemyPosList = new vector<Cell*>();
    for (int i = 0; i < enemyList->size(); i++) {
        enemyPosList->push_back(enemyList->at(i)->getPosition());
    }
    
    std::vector<IProjectile*> * projectList = adaptee->getProjectList();
    std::vector<Cell*> * projectilePos = new vector<Cell*>();
    for (int i = 0; i < projectList->size(); i++) {
        projectilePos->push_back(projectList->at(i)->getPosition());
    }
    vm->update(row_size, col_size, playerFighterPos, enemyPosList, projectilePos, gs, score, hp);
}
