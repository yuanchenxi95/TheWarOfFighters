//
//  Counter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "Counter.hpp"



Counter::Counter(int *coolDown) {
    if (coolDown < 0) {
        std::cerr << "counter should not be negative" << std::endl;
    }
    
    coolDownTime = coolDown;
    
    counter = 0;
    
}

Counter::~Counter() {
    coolDownTime = NULL;
}

void Counter::tick() {
    if (counter > 0) {
        counter--;
    }
}

void Counter::reset() {
    counter = *coolDownTime;
}

int* Counter::getCounter() {
    return coolDownTime;
}

bool Counter::isCoolDown() {
    return counter == 0;
}

void Counter::set(int* i) {
    coolDownTime = i;
}