//
//  IProjectile.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "IProjectile.hpp"
#include <stdexcept>



IProjectile::IProjectile(Cell* c, int damage, ProjectileType p, Direction d) {
    this->position = c;
    this->damage = damage;
    this->projType = p;
    this->direction = d;
}


IProjectile::~IProjectile() {
    
}

Cell* IProjectile::setPosition(Cell* c) {
    this->position = c;
    return this->position;
}

Cell* IProjectile::getPosition(Cell* c) {
    return this->position;
}


int IProjectile::setDamage(int d) {
    this->damage = d;
    return this->damage;
}

int IProjectile::getDamage() {
    return this->damage;
}

// tick this projectile
IProjectile* IProjectile::tickProjectile() {
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
    return this;
    
}

// get the type of this fighter(EnemyFighter, PlayerFighter)
ProjectileType IProjectile::getProjectileType() {
    return this->projType;
}

// get the direction of this projectile
Direction IProjectile::getDirection() {
    return this->direction;
}


