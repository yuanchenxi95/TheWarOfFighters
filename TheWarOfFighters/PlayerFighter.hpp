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

class PlayerFighter : public IFighter{
public:
    
    PlayerFighter(Cell* c, int health);
    ~PlayerFighter();
    
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    FighterType getFigterType();
    
    
protected:
    
private:
    
    
};


#endif /* PlayerFighter_hpp */
