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
#include <vector>

User::User(Serwer* serwer): IP(nullptr), ID(serwer->giveIdToNewUser()), friendsList(nullptr), devicesList(nullptr), messList(nullptr) {
    
    friendsList = new std::vector<User>();
    devicesList = new std::vector<device>();
    messList = new std::vector<std::string>();

} // set id

bool User::askServerForPermissionToAddNewFriendAndIfSoAdd(User* user, Serwer* serwer)
{
    if (serwer->addToFriendsList(this, user)) {
        return 1;
    } else {
        friendsList->push_back(*user);
    }
    return 0;
}

bool User::removeFriendFromFriendsList(User* user)
{
    for (friendIter = friendsList->begin(); friendIter != friendsList->end(); ++friendIter)
    {
        if (friendIter->ID == user->ID)
        {
            friendsList->erase(friendIter);
            return 0;
        }
    }

    return 1;
}

bool User::removeDeviceFromDevicessList(device* dev)
{
    for (devIter = devicesList->begin(); devIter != devicesList->end(); ++devIter)
    {
        //if (devIter->ID == dev->) potrzebuje cos z dev do zabicia
        {
            friendsList->erase(friendIter);
            return 0;
        }
    }
    
    return 1;
}


const std::vector<const User>::iterator User::getUserListIterator()
{
    return friendsList->cbegin();
}

const std::vector<const device>::iterator User::getDeviceListIterator()
{
    return devicesList->cbegin();

}

const std::vector<const std::string>::iterator User::getMessageIterator()
{
    return messList->cbegin();

}

















#endif
