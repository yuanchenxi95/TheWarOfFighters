//
//  EnemyFighter.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef EnemyFighter_hpp
#define EnemyFighter_hpp

#include <stdio.h>
#include "IFighter.hpp"

enum EnemyFighterType {
    ZOMBIEENEMYFIGHTER,
    ALIVEENEMYFIGHTER,
    DEADENEMYFIGHTER,
};

class EnemyFighter : public IFighter {
public:
    
    EnemyFighter(Cell* c, int health, Direction d);
    ~EnemyFighter();
    
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    FighterType getFigterType();
    
    // set the enemy fighter type
    EnemyFighterType setEnemyType(EnemyFighterType);
    
    // get the enemy fighter type
    EnemyFighterType getEnemyType();
    
    int getDamage(int d);

    // update the state of this fighter
    void updateFighter();
    
    // move the enemy to this->direction
    void moveThisFighter();
    
    
protected:
    
private:
    
    EnemyFighterType eft;
    
};

#endif /* EnemyFighter_hpp */
