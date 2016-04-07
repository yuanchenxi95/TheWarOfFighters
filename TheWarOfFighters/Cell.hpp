//
//  Cell.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/5.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class Cell {
public:
    
    Cell(int x, int y);
    // destructor
    virtual ~Cell() = 0;
    
    
    // get the position of this cell
    int getX();
    int getY();
    
    Cell* getUp();
    Cell* getDown();
    Cell* getRight();
    Cell* getLeft();
    
    Cell* setUp(Cell* up);
    Cell* setDown(Cell* down);
    Cell* setLeft(Cell* left);
    Cell* setRight(Cell* right);
  
    
protected:
    // the position of this tile
    int posX;
    int posY;
    
    Cell* up;
    Cell* down;
    Cell* right;
    Cell* left;
    
    
private:
    Cell& operator=(const Cell & other);
    
};




#endif /* Cell_hpp */
