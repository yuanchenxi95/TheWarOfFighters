//
//  View.cpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//
#include "IWOFModel.hpp"
#include "View.hpp"
#include "ViewModel.hpp"

View::View(IWOFModel* adaptee) {
    this->adaptee = adaptee;
}

View::~View(){
    
}

ViewModel* View::ModelToViewModel(IWOFModel* adaptee) {
    return new ViewModel(adaptee->row_size, adaptee->col_size, adaptee->player_pos, adaptee->enemy_pos);