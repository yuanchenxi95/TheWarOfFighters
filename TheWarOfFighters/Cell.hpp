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
    //todo: implement these methods
    void setPosition(int col, int row);
    void moveUp(int col, int row);
    void moveDown(int col, int row);
    void moveLeft(int col, int row);
    void moveRight(int col, int row);
  
    
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
