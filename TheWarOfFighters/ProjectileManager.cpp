//
//  ProjectileManager.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "ProjectileManager.hpp"


ProjectileManager::ProjectileManager() {
    this->lop = new std::vector<IProjectile*>();
}

ProjectileManager::~ProjectileManager() {
    
    typename std::vector<IProjectile*>::iterator iter= this->lop->begin();
    while(iter != lop->end()) {
        delete(*iter);
        ++iter;
    }
    lop->clear();
}

// get the list of projectiles in this manager
std::vector<IProjectile*> * ProjectileManager::getLop() {
    return this->lop;
}

// tick projectiles
std::vector<IProjectile*> * ProjectileManager::tickLop() {
    
    
    std::vector<IProjectile*> * nlop = new std::vector<IProjectile*>();
    for(IProjectile * p : *this->lop) {
        if (!p->tickProjectile()) {
            nlop->push_back(p);
        }
    }
    
    // delete the old lop
    lop->clear();
    
    lop = nlop;
    
    return this->lop;
}

// add the projectile to the manager
std::vector<IProjectile*> * ProjectileManager::addProj(IProjectile * p) {
    this->lop->push_back(p);
    return this->lop;
}






