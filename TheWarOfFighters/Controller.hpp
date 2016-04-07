//
//  Controller.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp
#include <ncurses.h>
#include <stdio.h>
#include "IFighter.hpp"
class Controller {
public:
    void handleKeys();
    Controller(IFighter* fighter);
    ~Controller();
protected:
    IFighter* fighter;
};
#endif /* Controller_hpp */
