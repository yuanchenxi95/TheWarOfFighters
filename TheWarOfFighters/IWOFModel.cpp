//
//  IWOFModel.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "IWOFModel.hpp"


//FightersManager(ProjectileManager * p, Map * map);

IWOFModel::IWOFModel(int height, int width) {
    this->score = 0;
    this->map = new Map(height, width);
    
    this->pm = new ProjectileManager();
    this->fm = new FightersManager(this->pm, this->map);
    this->gameState = PLAYING;
}

IWOFModel::~IWOFModel() {
    delete pm;
    
    delete fm;
    
    delete map;
}

vector<vector<Cell*>*> * IWOFModel::getBoard() {
    return this->map->getMap();
}

void IWOFModel::shoot() {
    this->fm->shoot();
}

vector<EnemyFighter*> * IWOFModel::getEnemyFighterList() {
    
   
    return this->fm->getEnemyFighters();
}

PlayerFighter * IWOFModel::getPlayerFighter() {
    return this->fm->getPlayerFighter();
}

vector<IProjectile*> * IWOFModel::getProjectList() {
    return this->pm->getLop();
}

int IWOFModel::getPlayerHealth() {
    return this->getPlayerFighter()->getHealth();
}

int IWOFModel::getScore() {
    return this->score;
}

void IWOFModel::tick() {
    this->score += this->fm->tick();
    
    if (this->fm->getPlayerFighter()->getHealth() <= 0) {
        this->setGameState(GAMEMOVER);
    }
}

// returns the current game state
GameState IWOFModel::getGameState() {
    return gameState;
}

// sets the current GameState to the given state
void IWOFModel::setGameState(GameState newState) {
    gameState = newState;
}



void IWOFModel::moveUp() {
    this->getPlayerFighter()->moveUp();
}
void IWOFModel::moveDown() {
    this->getPlayerFighter()->moveDown();
}
void IWOFModel::moveLeft() {
    this->getPlayerFighter()->moveLeft();
}
void IWOFModel::moveRight() {
    this->getPlayerFighter()->moveRight();
}
