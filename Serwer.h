//
//  Serwer.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __KomunikatorV2__Serwer__
#define __KomunikatorV2__Serwer__
#include "User.h"

class Serwer
{
    int currentID;
    
    
public:
    
    
    bool addToFriendsList(User*, User*);
    int giveIdToNewUser();
    
};
#endif /* defined(__KomunikatorV2__Serwer__) */
