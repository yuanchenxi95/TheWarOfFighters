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
#include "IWOFModel.hpp"
#include <time.h>
#include "Adapter.hpp"
#include "TerminalView.hpp"

class Controller {
public:
    Controller();
    ~Controller();
    // handle the keys
    void handleKeys();
    void startLoop();
    void welcome();
    
protected:
    IWOFModel * iwom;
    ViewModel * vm;
    TerminalView * view;
    Adapter * adapter;
    time_t startTime;
    time_t curTime;
    time_t curTime2;
};
#endif /* Controller_hpp */
