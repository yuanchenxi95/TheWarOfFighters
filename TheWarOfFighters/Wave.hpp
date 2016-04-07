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
    
    // tick and move the wave.
    void tick();
    
    // return ture if there is an enemy to be spawned
    bool anyEnemyToSpawn();
    
    
    // update enemy list, remove the dead enemies
    void updateList();
    
    // are all the enemies dead
    bool allEnemiesDead();
    
    // get the enemy list
    vector<EnemyFighter *> * getEnemies();
    
    // move and spawn the enemy, return how many enemies reach the end
    int move();
    
private:
    
    Counter * spawnCounter;
    
    vector<EnemyFighter*>* lof;
    
    
    // move the enemy
    void moveHelp(EnemyFighter *);
    
    // remove the enemy in the list and hashmap, delete the enemy
    void removeEnemy(EnemyFighter *, int);
    
    // kill the enemies that reach the end
    int killEndEnemy();
    
    // spawn an enemy on board
    void spawnEnemy(EnemyFighter * e);
    
};

#endif /* Wave_hpp */
