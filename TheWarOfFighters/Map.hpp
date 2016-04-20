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
    
    std::vector<std::vector<Cell *>*> * getMap();
    std::vector<Cell *> * getRightMostCells();
    std::vector<Cell *> * getLeftMostCells();
    int height;
    int width;
    
private:
    std::vector<std::vector<Cell *>*> * voc;
    void initializeMap(int width, int height);

    
};


#endif /* Map_hpp */
