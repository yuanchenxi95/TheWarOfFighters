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

class EnemyFighter : public IFighter {
public:
    
    EnemyFighter(Cell* c, int health);
    ~EnemyFighter();
    
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    FighterType getFigterType();

    
protected:
    
private:
    
};

#endif /* EnemyFighter_hpp */
