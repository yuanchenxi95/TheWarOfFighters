//
//  ProjectileManager.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "ProjectileManager.hpp"


ProjectileManager::ProjectileManager() {
    this->lop = new vector<IProjectile*>();
}

ProjectileManager::~ProjectileManager() {
    
    typename vector<IProjectile*>::iterator iter= this->lop->begin();
    while(iter != lop->end()) {
        delete(*iter);
        ++iter;
    }
    lop->clear();
}

// get the list of projectiles in this manager
vector<IProjectile*> * ProjectileManager::getLop() {
    return this->lop;
}

// tick projectiles
vector<IProjectile*> * ProjectileManager::tickLop() {
    
    
    vector<IProjectile*> * nlop = new vector<IProjectile*>();
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
vector<IProjectile*> * ProjectileManager::addProj(IProjectile * p) {
    this->lop->push_back(p);
    return this->lop;
}






