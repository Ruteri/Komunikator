//
//  User.cpp
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __USER_CPP__
#define __USER_CPP__

#include "User.h"
#include <iostream>


User::User(Serwer* serwer): IP(nullptr), friendsList(), devicesList() {} // set id

bool User::askServerForPermissionToAddNewFriendAndIfSoAdd(User* user, Serwer* serwer)
{
    return 0;
}

int User::getIDFromSerwer(Serwer* serwer)
{
    return serwer?serwer->giveIdToNewUser():0;
}

#endif
