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
    for(IProjectile * p : *this->lop) {
        p->tickProjectile();
    }
    
    return this->lop;
}





