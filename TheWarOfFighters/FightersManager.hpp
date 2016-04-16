//
//  FightersManager.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef FightersManager_hpp
#define FightersManager_hpp

#include <stdio.h>

#include <vector>
#include "ProjectileManager.hpp"
#include "IFighter.hpp"
#include "PlayerFighter.hpp"
#include "Wave.hpp"
#include "Map.hpp"

class FightersManager {
public:
    
    FightersManager(ProjectileManager * p, Map * map);
    ~FightersManager();
    
    // tick the world and return the number of dead enemies
    int tick();
    // player shoot
    void shoot();
    
    ProjectileManager * getProjectileManager();
    vector<EnemyFighter*> * getEnemyFighters();
    Map * getMap();
    PlayerFighter * getPlayerFighter();
    void hitFighter();
    
protected:
    
    
    
private:
    ProjectileManager * pm;
    Wave * wave;
    Map * map;
    PlayerFighter * player;
    
    void addProjectile();
    void initializeEnemyList(vector<EnemyFighter*> **);
    
};


#endif /* FightersManager_hpp */
