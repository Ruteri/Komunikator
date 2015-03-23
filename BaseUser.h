//
//  BaseUser.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __KomunikatorV2__BaseUser__
#define __KomunikatorV2__BaseUser__
#include "Serwer.h"
#include <string>

class BaseUser
{
    const int ID;
    const std::string Nick;
    
public:
    const inline int getID() const { return ID; }
    BaseUser(int Id, std::string nick): ID(Id), Nick(nick) {}
    
};



#endif /* defined(__KomunikatorV2__BaseUser__) */
