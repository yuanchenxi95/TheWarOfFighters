//
//  IFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "IFighter.hpp"


IFighter::IFighter(Cell* c, int health, Direction d, int damage) {
    this->position = c;
    this->health = health;
    this->direction = d;
    this->damage = damage;
}


IFighter::~IFighter() {
    
}

Cell* IFighter::setPosition(Cell* c) {
    this->position = c;
    return this->position;
}

Cell* IFighter::getPosition() {
    return this->position;
}


int IFighter::setHealth(int h) {
    this->health = h;
    return this->health;
}

int IFighter::getHealth() {
    return this->health;
}

int IFighter::getDamage() {
    return this->damage;
}

Cell* IFighter::moveUp() {
    this->position = this->position->getUp();
    return this->position;
}
Cell* IFighter::moveDown() {
    this->position = this->position->getDown();
    return this->position;
}
Cell* IFighter::moveRight() {
    this->position = this->position->getRight();
    return this->position;
}
Cell* IFighter::moveLeft() {
    this->position = this->position->getLeft();
    return this->position;
}

Direction IFighter::getDirection() {
    return this->direction;
}
