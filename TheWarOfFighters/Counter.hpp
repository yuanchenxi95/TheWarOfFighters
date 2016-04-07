//
//  Counter.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef Counter_hpp
#define Counter_hpp

#include <stdio.h>
#include <iostream>

class Counter {
public:
    Counter(int*);
    ~Counter();
    
    // if counter > 0, sub 1 to the counter. otherwise, do nothing
    void tick();
    
    // reset the counter to the default number.
    void reset();
    
    // get the counter
    int* getCounter();
    
    // is it cool down
    bool isCoolDown();
    
    // set the coolDownToThe given int
    void set(int*);
    
private:
    int counter;
    int * coolDownTime;
};

#endif /* Counter_hpp */
