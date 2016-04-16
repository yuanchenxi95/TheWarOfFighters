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
Adapter::Adapter(IWOFModel* adaptee) {
    this->adaptee = adaptee;
}

Adapter::~Adapter(){
    
}

ViewModel* Adapter::ModelToViewModel(IWOFModel* adaptee) {
    int row_size = sizeof(adaptee->getBoard()->at(0));
    int col_size = sizeof(adaptee->getBoard());
    GameState gs = adaptee->getGameState();
    Cell* playerFighterPos = adaptee->getPlayerFighter()->getPosition();
    std::vector<EnemyFighter*> * enemyList = adaptee->getEnemyFighterList();
    std::vector<Cell*> * enemyPosList = new vector<Cell*>(sizeof(enemyList));
    std::cout<<enemyList->size()<<"\n";
    for (int i = 0; i < enemyList->size(); i++) {
        enemyPosList->push_back(enemyList->at(0)->getPosition());
    }
    
    std::vector<IProjectile*> * projectList = adaptee->getProjectList();
    std::vector<Cell*> * projectilePos = new vector<Cell*>(sizeof(projectList));
    for (int i = 0; i < projectList->size(); i++) {
        projectilePos->push_back(projectList->at(0)->getPosition());
    }
    return new ViewModel(row_size, col_size, playerFighterPos, enemyPosList, projectilePos, gs);
}
