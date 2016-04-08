//
//  Map.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Cell.hpp"


class Map {
public:
    Map(int height, int width);
    ~Map();
    
    vector<vector<Cell *>*> * getMap();
    vector<Cell *> * getRightMostCells();
    vector<Cell *> * getLeftMostCells();
    int height;
    int width;
    
private:
    vector<vector<Cell *>*> * voc;
    void initializeMap(int width, int height);

    
};


#endif /* Map_hpp */
