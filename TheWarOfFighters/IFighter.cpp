//
//  IFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "IFighter.hpp"


IFighter::IFighter(Cell* c) {
    this->position = c;
}


IFighter::~IFighter() {
    
}

Cell* IFighter::setPosition(Cell* c) {
    this->position = c;
    return this->position;
}

Cell* IFighter::getPosition(Cell* c) {
    return this->position;
}


