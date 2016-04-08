//
//  IWOFModel.hpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#ifndef IWOFModel_hpp
#define IWOFModel_hpp

#include <stdio.h>
#include <vector>
#include "ProjectileManager.hpp"
#include "FightersManager.hpp"


class IWOFModel {
public:
    IWOFModel(int height, int width);
    ~IWOFModel();
    
    
    vector<vector<Cell*>*> * getBoard();
    void shoot();
    vector<EnemyFighter*> * getEnemyFighterList();
    PlayerFighter * getPlayerFighter();
    vector<IProjectile*> * getProjectList();
    int getPlayerHealth();
    int getScore();
    
    void tick();
    
    
protected:
    
private:
    FightersManager * fm;
    int score;
    Map * map;
    ProjectileManager * pm;
};

#endif /* IWOFModel_hpp */
