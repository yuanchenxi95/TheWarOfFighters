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

// gamestate constants
enum GameState {
    QUIT,
    PLAYING,
    GAMEMOVER,
    MENU
};

class IWOFModel {
public:
    IWOFModel(int height, int width);
    ~IWOFModel();
    
    
    std::vector<std::vector<Cell*>*> * getBoard();
    void shoot();
    std::vector<EnemyFighter*> * getEnemyFighterList();
    PlayerFighter * getPlayerFighter();
    std::vector<IProjectile*> * getProjectList();
    int getPlayerHealth();
    int getScore();
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    
    // returns game state
    GameState getGameState();
    
    // sets the current GameState to the given state
    void setGameState(GameState newState);
    
    
    void tick();
    
    
protected:
    
private:
    GameState gameState = PLAYING;         // game loop flag
    
    FightersManager * fm;
    int score;
    Map * map;
    ProjectileManager * pm;
};

#endif /* IWOFModel_hpp */
