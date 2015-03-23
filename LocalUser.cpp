//
//  LocalUser.cpp
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#include "LocalUser.h"

bool LocalUser::receiveMessage(Message msg)
{
    recieveMessage(msg.getSender(), msg.getText());
    
    std::vector<const FriendUser>::iterator iter;
    for (iter = FriendsVector->begin(); iter != FriendsVector->end(); ++iter) {
        if (iter->getID() == msg.getSender()->getID()) { iter->pushMessage(msg); return 0; }
        
    }
    
    
    // LUB
    (*FriendsMap)[msg.getSender()->getID()].pushMessage(msg);
    
    
    return 0;
    
}

bool LocalUser::askServerForPermissionToAddNewFriendAndIfSoAdd(Serwer* serwer, int Id, std::string nick)
{
    //if( !serwer->requestingFriendAdd(Id))
    
    
    const FriendUser newFriend(Id, nick);
    FriendsVector->push_back(newFriend);
    
    // LUB
    
    //(*FriendsMap)[Id] = new FriendUser(Id, nick);
    
    return 0;
}

bool LocalUser::checkIfHasFriend(int Id)
{
    //std::map<const int, const FriendUser>::iterator iterM;
    //iterM = FriendsMap->find(Id);
    
    //if (iterM->first != 0) return true;
    
    // LUB
    
    std::vector<const FriendUser>::iterator iter;
    
    for (iter = FriendsVector->begin(); iter != FriendsVector->end(); ++iter)
    {
        if (iter->getID() == Id) {
            return true;
        }
    }
    
    return false;

    
}

bool LocalUser::removeFriendFromFriendsList(int Id)
{
    //std::map<const int, const FriendUser>::iterator iterM;
    //if (iterM->first != 0)
    //    FriendsMap->erase(iterM);
    
    // LUB
    
    std::vector<const FriendUser>::iterator iter;
    
    for (iter = FriendsVector->begin(); iter != FriendsVector->end(); ++iter)
    {
        if (iter->getID() == Id)
        {
            FriendsVector->erase(iter);
            return 0;
        }
    }

    return 1;
}

bool LocalUser::removeDeviceFromDevicessList(int Id) // POTRZEBUJE ID DEVICE!!!!
{
    std::vector<const device>::iterator iter;
    
    for (iter = DevicesList->begin(); iter != DevicesList->end(); ++iter)
    {
        if (iter->getID() == Id)
        {
            DevicesList->erase(iter);
            return 0;
        }
    }
    
    return 1;

}


std::vector<const FriendUser>::iterator LocalUser::getFriendUserListIterator() const
{
    return FriendsVector->begin();
}
std::vector<const device>::iterator LocalUser::getDeviceListIterator() const
{
    return DevicesList->begin();
}
