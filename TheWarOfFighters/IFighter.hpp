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
    IFighter(Cell* c);
    ~IFighter();
    
    Cell* setPosition(Cell* c);
    Cell* getPosition(Cell* c);
    
    // get the type of this fighter(EnemyFighter, PlayerFighter)
    virtual FighterType getFigterType() = 0;
    
    
protected:
    Cell * position;
    
    
private:
    
};
#endif /* IFighter_hpp */
