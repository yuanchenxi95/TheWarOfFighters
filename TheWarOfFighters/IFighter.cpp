//
//  IFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "IFighter.hpp"


IFighter::IFighter(Cell* c, int health, Direction d) {
    this->position = c;
    this->health = health;
    this->direction = d;
}


IFighter::~IFighter() {
    
}

Cell* IFighter::setPosition(Cell* c) {
    this->position = c;
    return this->position;
}

Cell* IFighter::getPosition(Cell* c) {
    return this->position;
}


int IFighter::setHealth(int h) {
    this->health = h;
    return this->health;
}

int IFighter::getHealth() {
    return this->health;
}
