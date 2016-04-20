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

class ProjectileManager {
public:
    ProjectileManager();
    ~ProjectileManager();
    
    // get the list of projectiles in this manager
    std::vector<IProjectile*> * getLop();
    
    // tick projectiles
    std::vector<IProjectile*> * tickLop();
    
    // add the projectile to the manager
    std::vector<IProjectile*> * addProj(IProjectile * p);
    
    
protected:
    std::vector<IProjectile*> * lop;
    
private:
    
    
    
};

#endif /* ProjectileManager_hpp */
