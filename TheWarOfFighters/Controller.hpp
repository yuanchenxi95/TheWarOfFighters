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
#include "IProjectile.cpp"
class Controller {
public:
    void handleKeys();
    Controller(IProjectile* projectile);
    ~Controller();
protected:
    IProjectile* projectile;
};
#endif /* Controller_hpp */
