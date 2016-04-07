//
//  MyFighter.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//


#include "IFighter.hpp"
class MyFighter : public IFighter {
    public:
    char figher_char = '>';
    FighterType ft = PLAYERFIGHTER;
    FighterType getFighterType() {
        return ft;
    }
    
};