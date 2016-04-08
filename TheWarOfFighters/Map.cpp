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
        cerr << "Map must be bigger than 5 * 5" << endl;
    }
    
    this->height = height;
    this->width = width;
    this->initializeMap(width, height);
}

Map::~Map() {
    for (vector<Cell*> * v: *this->voc) {
        v->clear();
    }
    
    this->voc->clear();
    delete voc;
}

vector<vector<Cell *>*> * Map::getMap() {
    return this->voc;
}

vector<Cell *> * Map::getRightMostCells() {
    int i;
    vector<Cell *> * rightMostCells = new vector<Cell*>();
    for (i = 0; i < this->height; i++) {
        rightMostCells->push_back(this->voc->at(i)->at(this->width-1));
    }
    
    return rightMostCells;
    
}

vector<Cell *> * Map::getLeftMostCells() {
    int i;
    vector<Cell *> * leftMostCells = new vector<Cell*>();
    for (i = 0; i < this->height; i++) {
        leftMostCells->push_back(this->voc->at(i)->at(0));
    }
    return leftMostCells;
}


void Map::initializeMap(int width, int height) {
    
    voc = new vector<vector<Cell*>*>();
    
    
    int i, j;
    for (i = 0; i < height; i++) {
        voc->push_back(new vector<Cell*>);
        
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