//
//  PlayerFighter.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef PlayerFighter_hpp
#define PlayerFighter_hpp

#include <stdio.h>
#include "IFighter.hpp"

enum PlayerFighterType {
    ALIVEPLAYER,
    DEADPLAYER,
};

class PlayerFighter : public IFighter{
public:
    
    PlayerFighter(Cell* c, int health, Direction d);
    ~PlayerFighter();
    
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    FighterType getFigterType();
    
    PlayerFighterType getPlayerState();
    PlayerFighterType setPlaterState(PlayerFighterType);
    
    int getDamage(int d);
    void updateFighter();
    
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    
protected:
    
private:
    
    PlayerFighterType pft;
};


#endif /* PlayerFighter_hpp */
