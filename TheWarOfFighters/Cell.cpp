//
//  Cell.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/5.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "Cell.hpp"


Cell::Cell(int x, int y) {
    
    this->posX = x;
    this->posY = y;
}

Cell::~Cell() {
    
}

Cell* Cell::getUp() {
    return this->up;
}


Cell* Cell::getDown() {
    return this->down;
}
Cell* Cell::getRight() {
    return this->right;
}
Cell* Cell::getLeft() {
    return this->left;
}


Cell* Cell::setUp(Cell* up) {
    this->up = up;
    return this->up;
}

Cell* Cell::setDown(Cell* down) {
    this->down = down;
    return this->down;
}

Cell* Cell::setLeft(Cell* left) {
    this->left = left;
    return this->left;
}

Cell* Cell::setRight(Cell* right) {
    this->right = right;
    return this->right;
}


int Cell::getX() {
    return posX;
}

int Cell::getY() {
    return posY;
}