//
//  Adapter.hpp
//  TheWarOfFighters
//
//  Created by Leyi Qiang on 4/13/16.
//  Copyright © 2016 Chenxi Yuan. All rights reserved.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <stdio.h>
#include "IWOFModel.hpp"
#include "ViewModel.hpp"
class Adapter {
public:
    Adapter(IWOFModel* adaptee);
    ~Adapter();
    IWOFModel* adaptee;
    ViewModel* ModelToViewModel(IWOFModel* adaptee);
    
};
#endif /* Adapter_hpp */
