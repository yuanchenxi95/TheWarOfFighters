//
//  ProjectileManager.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef ProjectileManager_hpp
#define ProjectileManager_hpp

#include <stdio.h>
#include <vector>
#include "IProjectile.hpp"
using namespace std;

class ProjectileManager {
public:
    ProjectileManager();
    ~ProjectileManager();
    
    // get the list of projectiles in this manager
    vector<IProjectile*> * getLop();
    
    // tick projectiles
    vector<IProjectile*> * tickLop();
    
protected:
    vector<IProjectile*> * lop;
    
private:
    
    
    
};

#endif /* ProjectileManager_hpp */
