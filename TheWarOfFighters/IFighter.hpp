//
//  IFighter.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef IFighter_hpp
#define IFighter_hpp

#include <stdio.h>

#include "Cell.hpp"

enum FighterType {
    ENEMYFIGHTER,
    PLAYERFIGHTER,
};

class IFighter {
public:
    
    IFighter(Cell* c, int health, Direction d);
    ~IFighter();
    
    Cell* setPosition(Cell* c);
    Cell* getPosition(Cell* c);
    
    int getHealth();
    int setHealth(int h);
    
    Cell* moveUp();
    Cell* moveDown();
    Cell* moveRight();
    Cell* moveLeft();
    
    Direction getDirection();
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    virtual FighterType getFigterType() = 0;

    // get the damage, return the health
    virtual int getDamage(int d) = 0;
    
    // update the state of this fighter
    virtual void updateFighter() = 0;
    
    
protected:
    Cell * position;
    int health;
    Direction direction;
    
private:
    
};
#endif /* IFighter_hpp */
