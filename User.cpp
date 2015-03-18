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

User::User(int ID): friendsList(), devicesList(), IP(nullptr) {}
// comsubject (ID)
User::User(Serwer* serwer): IP(nullptr), friendsList(), devicesList() {} // set id

bool User::askServerForPermissionToAddNewFriendAndIfSoAdd(User* user, Serwer* serwer)
{
    if (serwer->addToFriendsList(this, user)) {
        return 1;
    } else {
        this->friendsList.push_back(*user);
    }
    return 0;
}

bool User::removeFriendFromFriendsList(User* user)
{
}



#endif
