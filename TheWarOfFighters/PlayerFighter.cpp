//
//  PlayerFighter.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/7.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include "PlayerFighter.hpp"

PlayerFighter::PlayerFighter(Cell * c, int health, Direction d) : IFighter(c, health, d, 5) {
    pft = ALIVEPLAYER;
}

PlayerFighter::~PlayerFighter() {
    
}




FighterType PlayerFighter::getFighterType() {
    return PLAYERFIGHTER;
}

int PlayerFighter::damageThisFighter(int d) {
    this->health -= d;
    if (this->health <= 0) {
        this->pft = DEADPLAYER;
    }
    return this->health;
}

PlayerFighterType PlayerFighter::getPlayerState() {
    return this->pft;
}

PlayerFighterType PlayerFighter::setPlaterState(PlayerFighterType pft) {
    this->pft = pft;
    return this->pft;
}

void PlayerFighter::updateFighter() {
    if (this->health <= 0) {
        this->pft = DEADPLAYER;
    }
}

void PlayerFighter::moveUp() {
    this->position->getUp();
}
void PlayerFighter::moveDown() {
    this->position->getDown();
}
void PlayerFighter::moveLeft() {
    this->position->getLeft();
}
void PlayerFighter::moveRight() {
    this->position->getRight();
}
