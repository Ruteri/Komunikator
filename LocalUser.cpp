//
//  LocalUser.cpp
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#include "LocalUser.h"
void LocalUser::recieveMessage(Message msg)
{
    Message newMsg(msg.getSender(), msg.getReciever(), msg.getText());
    ComSubject::recieveMessage(newMsg);
    
    std::vector<ComSubject>::iterator iter;
    iter = FriendsVector->begin();
    for (; iter != FriendsVector->end(); ++iter) {
        if (iter->getID() == msg.getSender()->getID()) {
            iter->recieveMessage(newMsg);
        }
    }
}

bool LocalUser::askServerForPermissionToAddNewFriendAndIfSoAdd(Serwer* serwer, int Id, std::string nick)
{
    
    //if( !serwer->requestingFriendAdd(Id))
    ComSubject newFriend = *new ComSubject(Id);
    FriendsVector->push_back(newFriend);
    
    (*MessageMap)[Id] = new std::vector<Message>;
    
    return 0;
}

bool LocalUser::checkIfHasFriend(int Id)
{
    std::vector<const ComSubject>::iterator iter;
    
    for (iter = FriendsVector->begin(); iter != FriendsVector->end(); ++iter)
    {
        if (iter->getID() == Id) {
            return true;
        }
     }
    
    return false;

    
}


bool LocalUser::removeFriendFromFriendsList(int Id) const
{
    // LUB
    
    std::vector<ComSubject>::iterator iter;
    int i;
    for (i = 0, iter = FriendsVector->begin(); iter != FriendsVector->end(); ++iter, ++i)
    {
        if (iter->getID() == Id)
        {
            iter->ComSubject::~ComSubject();
            //FriendsVector->erase(iter);
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
            //DevicesList->erase(iter);
            return 0;
        }
    }
    
    return 1;

}


std::vector<const ComSubject>::iterator LocalUser::getFriendUserListIterator() const
{
    return FriendsVector->cbegin();
}
std::vector<const device>::iterator LocalUser::getDeviceListIterator() const
{
    return DevicesList->cbegin();
}
