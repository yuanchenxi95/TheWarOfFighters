//
//  IProjectile.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef IProjectile_hpp
#define IProjectile_hpp

#include <stdio.h>


#include "Cell.hpp"

enum ProjectileType {
    ENEMYPORJECTILE,
    PLAYERPROJECTILE,
    ZOMBIEPROJECTILE,
};

class IProjectile {
public:
    
    IProjectile(Cell* c, int damage, ProjectileType p, Direction);
    ~IProjectile();
    
    Cell* setPosition(Cell* c);
    Cell* getPosition();
    
    int getDamage();
    int setDamage(int d);
    
    // tick this projectile, return true if this projectile is the zombie projectile
    bool tickProjectile();
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    ProjectileType getProjectileType();
    
    // set the type of this fighter(EnemyFighter, PlayerFighter)
    void setProjectileType(ProjectileType p);
    
    // get the direction of this projectile
    Direction getDirection();
    
    
    
protected:
    Cell * position;
    int damage;
    ProjectileType projType;
    Direction direction;
    
private:
    
};


#endif /* IProjectile_hpp */
