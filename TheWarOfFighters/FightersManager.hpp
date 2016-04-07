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

class FightersManager {
public:
    
    FightersManager();
    ~FightersManager();
    
protected:
    
    
    
private:
    ProjectileManager * fm;
    
    
};


#endif /* FightersManager_hpp */
