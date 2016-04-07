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
};

class IProjectile {
public:
    
    IProjectile(Cell* c, int damage, ProjectileType p, Direction);
    ~IProjectile();
    
    Cell* setPosition(Cell* c);
    Cell* getPosition(Cell* c);
    
    int getDamage();
    int setDamage(int d);
    
    // tick this projectile
    IProjectile* tickProjectile();
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    ProjectileType getProjectileType();
    
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
