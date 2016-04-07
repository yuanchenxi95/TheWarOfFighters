//
//  View.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/7/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "IWOFModel.hpp"
#include "ViewModel.hpp"
class View {
protected:
    View(IWOFModel* adaptee);
    ~View();
public:
    IWOFModel* adaptee;
    ViewModel* ModelToViewModel(IWOFModel* adaptee);
    
};
#endif /* View_hpp */
