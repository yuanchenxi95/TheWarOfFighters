//
//  Wave.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef Wave_hpp
#define Wave_hpp

#include <stdio.h>
#include "Cell.hpp"
#include "EnemyFighter.hpp"
#include <vector>
#include "Counter.hpp"

using namespace std;

class Wave{
public:
    Wave(vector<EnemyFighter*>*);
    ~Wave();

    
    // update enemy list, remove the dead enemies
    void updateList();
    
    // are all the enemies dead
    bool allEnemiesDead();
    
    // get the enemy list
    vector<EnemyFighter *> * getEnemies();
    
    // move and spawn the enemy, return how many enemies were killed in this wave
    int move();
    
private:

    
    vector<EnemyFighter*>* lof;
    
    // remove the bad enemies
    int removeBadEnemy();
    
    
};

#endif /* Wave_hpp */
