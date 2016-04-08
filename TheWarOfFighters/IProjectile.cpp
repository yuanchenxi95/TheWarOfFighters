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

Cell* IProjectile::getPosition() {
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
bool IProjectile::tickProjectile() {
    
    if (getDirection() == UP) {
        
        if (this->position == this->position->getUp()) {
            this->projType = ZOMBIEPROJECTILE;
        }
        
        this->position = this->position->getUp();
        this->position = this->position->getUp();
    } else if (getDirection() == DOWN) {
        if (this->position == this->position->getDown()) {
            this->projType = ZOMBIEPROJECTILE;
        }
        
        this->position = this->position->getDown();
        this->position = this->position->getDown();
    } else if (getDirection() == LEFT) {
        
        if (this->position == this->position->getLeft()) {
            this->projType = ZOMBIEPROJECTILE;
        }
        
        this->position = this->position->getLeft();
        this->position = this->position->getLeft();
    } else if (getDirection() == RIGHT) {
        
        if (this->position == this->position->getRight()) {
            this->projType = ZOMBIEPROJECTILE;
        }
        this->position = this->position->getRight();
        this->position = this->position->getRight();
        
    } else {
        throw std::invalid_argument( "UNKNOWN DIRECTION to move the porjectile" );
    }
    
    return this->projType == ZOMBIEPROJECTILE;;
    
}

// get the type of this fighter(EnemyFighter, PlayerFighter)
ProjectileType IProjectile::getProjectileType() {
    return this->projType;
}

// set the type of this fighter(EnemyFighter, PlayerFighter)
void IProjectile::setProjectileType(ProjectileType p) {
    this->projType = p;
}

// get the direction of this projectile
Direction IProjectile::getDirection() {
    return this->direction;
}


