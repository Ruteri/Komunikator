//
//  Serwer.cpp
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#include "Serwer.h"

bool Serwer::addToFriendsList(ComSubject* U1, ComSubject* U2)
{
    return 0;
}

int Serwer::giveIdToNewUser()
{
    //(*UserList)[UserList->size()] = LU1;
    return ++currentID;
}

bool Serwer::processMessage(Message msg)
{
    
    return 0;
}