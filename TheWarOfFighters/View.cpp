//
//  View.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//
#include "IWOFModel.hpp"
#include "View.hpp"
#include "ViewModel.hpp"
#include "IFighter.hpp"
#include "PlayerFighter.hpp"
#include "EnemyFighter.hpp"
#include <vector>
View::View(IWOFModel* adaptee) {
    this->adaptee = adaptee;
}

View::~View(){
    
}

ViewModel* View::ModelToViewModel(IWOFModel* adaptee) {
    int row_size = sizeof(adaptee->getBoard())[0];
    int col_size = sizeof(adaptee->getBoard());
    Cell* playerFighterPos = adaptee->getPlayerFighter()->getPosition();
    vector<EnemyFighter*> * enemyList = adaptee->getEnemyFighterList();
    vector<Cell*> * enemyPosList = new vector<Cell*>(sizeof(enemyList));
    for (int i = 0; i < sizeof(enemyList); i++) {
        enemyPosList->push_back(enemyList->at(0)->getPosition());
    }
    
    vector<IProjectile*> * projectList = adaptee->getProjectList();
    std::vector<Cell*> * projectilePos = new vector<Cell*>(sizeof(projectList));
    for (int i = 0; i < sizeof(projectList); i++) {
        projectilePos->push_back(projectList->at(0)->getPosition());
    }
    return new ViewModel(row_size, col_size, playerFighterPos, enemyPosList, projectilePos);
}
