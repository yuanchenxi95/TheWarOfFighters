//
//  Map.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "Map.hpp"


Map::Map(int height, int width) {
    if (height < 5 || width < 5) {
        std::cerr << "Map must be bigger than 5 * 5" << std::endl;
    }
    
    this->height = height;
    this->width = width;
    this->initializeMap(width, height);
}

Map::~Map() {
    for (std::vector<Cell*> * v: *this->voc) {
        v->clear();
    }
    
    this->voc->clear();
    delete voc;
}

std::vector<std::vector<Cell *>*> * Map::getMap() {
    return this->voc;
}

std::vector<Cell *> * Map::getRightMostCells() {
    int i;
    std::vector<Cell *> * rightMostCells = new std::vector<Cell*>();
    for (i = 0; i < this->height; i++) {
        rightMostCells->push_back(this->voc->at(i)->at(this->width-1));
    }
    
    return rightMostCells;
    
}

std::vector<Cell *> * Map::getLeftMostCells() {
    int i;
    std::vector<Cell *> * leftMostCells = new std::vector<Cell*>();
    for (i = 0; i < this->height; i++) {
        leftMostCells->push_back(this->voc->at(i)->at(0));
    }
    return leftMostCells;
}


void Map::initializeMap(int width, int height) {
    
    voc = new std::vector<std::vector<Cell*>*>();
    
    
    int i, j;
    for (i = 0; i < height; i++) {
        voc->push_back(new std::vector<Cell*>);
        
        for (j = 0; j < width; j++) {
            voc->at(i)->push_back(new Cell(j, i));
        }
    }
    
    // fix link
    for (i = 0; i < height; i++) {
        
        for (j = 0; j < width; j++) {
            
            Cell * ctmp = voc->at(i)->at(j);
            
            
            if (i == 0) {
                ctmp->setUp(ctmp);
            } else {
                ctmp->setUp(voc->at(i-1)->at(j));
            }
            
            if (i == height - 1) {
                ctmp->setDown(ctmp);
            } else {
                ctmp->setDown(voc->at(i+1)->at(j));
            }
            
            if (j == 0) {
                ctmp->setLeft(ctmp);
            } else {
                ctmp->setLeft(voc->at(i)->at(j-1));
            }
            
            if (j == width - 1) {
                ctmp->setRight(ctmp);
            } else {
                ctmp -> setRight(voc->at(i)->at(j+1));
            }
            
            
        }
        
        
    }
    
    
}