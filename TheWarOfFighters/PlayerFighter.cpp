//
//  PlayerFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "PlayerFighter.hpp"

PlayerFighter::PlayerFighter(Cell * c, int health) : IFighter(c, health) {
    
}

PlayerFighter::~PlayerFighter() {
    
}




FighterType PlayerFighter::getFigterType() {
    return PLAYERFIGHTER;
}
