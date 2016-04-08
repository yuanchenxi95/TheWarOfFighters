//
//  EnemyFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "EnemyFighter.hpp"
#include <stdexcept>

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

void EnemyFighter::updateFighter() {
    if (this->health <= 0) {
        this->eft = DEADENEMYFIGHTER;
    }
    
    if (getDirection() == UP) {
        
        if (this->position == this->position->getUp()) {
            this->eft = ZOMBIEENEMYFIGHTER;
        }
        
    } else if (getDirection() == DOWN) {
        if (this->position == this->position->getDown()) {
            
            this->eft = ZOMBIEENEMYFIGHTER;
        }
        
        this->position = this->position->getDown();
    } else if (getDirection() == LEFT) {
        
        if (this->position == this->position->getLeft()) {
            
            this->eft = ZOMBIEENEMYFIGHTER;
        }
        
    } else if (getDirection() == RIGHT) {
        
        if (this->position == this->position->getRight()) {
            
            this->eft = ZOMBIEENEMYFIGHTER;
        }
    } else {
        throw std::invalid_argument( "UNKNOWN DIRECTION to move the porjectile" );
    }

}

void EnemyFighter::moveThisFighter() {
    
    if (getDirection() == UP) {
        
        this->position = this->position->getUp();
    } else if (getDirection() == DOWN) {

        this->position = this->position->getDown();
    } else if (getDirection() == LEFT) {
        
        
        this->position = this->position->getLeft();
    } else if (getDirection() == RIGHT) {

        this->position = this->position->getRight();
    } else {
        throw std::invalid_argument( "UNKNOWN DIRECTION to move the porjectile" );
    }
    

}

