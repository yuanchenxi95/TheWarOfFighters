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
#include <chrono>
using namespace std::chrono;

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
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point curTime;
    high_resolution_clock::time_point curTime2;
};
#endif /* Controller_hpp */
