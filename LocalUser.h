//
//  LocalUser.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//
#include "device.h"
#include "Serwer.h"
#include "Message.h"
#include "ComSubject.h"
#include <map>


#ifndef __KomunikatorV2__LocalUser__
#define __KomunikatorV2__LocalUser__

class LocalUser : public ComSubject
{
    std::vector<ComSubject>* FriendsVector;
    std::vector<const device>* DevicesList;
    
    // LUB
    
    std::map<const int, std::vector<Message>*>* MessageMap;
    
    Serwer* serwer;
    
public:
    LocalUser(int Id, Serwer* s = nullptr): ComSubject(Id), serwer(s) { FriendsVector = new std::vector<ComSubject>; DevicesList = new std::vector<const device>; MessageMap = new std::map<const int, std::vector<Message>*>; }
    
        
    bool askServerForPermissionToAddNewFriendAndIfSoAdd(Serwer*, int Id = 0, std::string nick = NULL);
    
    bool checkIfHasFriend(int Id);
    bool removeFriendFromFriendsList(int Id) const;
    bool removeDeviceFromDevicessList(int Id); // POTRZEBUJE ID DEVICE!!!!
    
    void recieveMessage(Message);
    
    
    std::vector<const ComSubject>::iterator getFriendUserListIterator() const;
    std::vector<const device>::iterator getDeviceListIterator() const;
    std::vector<const std::string>::iterator getMessageIterator() const;
    
    
    
    friend std::ostream& operator<<(std::ostream& stream, LocalUser* lUser) {
        return stream;
    }
    
    
    
};

#endif /* defined(__KomunikatorV2__LocalUser__) */
