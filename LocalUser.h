//
//  LocalUser.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __KomunikatorV2__LocalUser__
#define __KomunikatorV2__LocalUser__
#include "BaseUser.h"
#include "FriendUser.h"
#include "device.h"
#include "Serwer.h"
#include "Message.h"
#include "ComSubject.h"
#include <map>

class LocalUser : public ComSubject
{
    std::vector<const FriendUser>* FriendsVector;
    std::vector<const device>* DevicesList;
    
    // LUB
    
    std::map< const int, const FriendUser >* FriendsMap;  // WSKAZANIE NA MAPĘ Z C. INT I WSKAZANIEM NA WEKTOR Z MESSAGE
    
public:
    
    bool receiveMessage(Message);
    
    bool askServerForPermissionToAddNewFriendAndIfSoAdd(Serwer*, int Id = 0, std::string nick = NULL);
    
    bool checkIfHasFriend(int Id);
    bool removeFriendFromFriendsList(int Id);
    bool removeDeviceFromDevicessList(int Id); // POTRZEBUJE ID DEVICE!!!!
    
    
    std::vector<const FriendUser>::iterator getFriendUserListIterator() const;
    std::vector<const device>::iterator getDeviceListIterator() const;
    std::vector<const std::string>::iterator getMessageIterator() const;
    
    
    
    friend std::ostream& operator<<(std::ostream& stream, LocalUser* lUser) {
        stream << "Friends: " << std::endl;
        
        std::vector<const FriendUser>::iterator iter;
        
        for (iter = lUser->FriendsVector->begin(); iter != lUser->FriendsVector->end(); ++iter) {
            stream << "ID: " << &iter << std::endl;
        }
        
        stream << std::endl << "Devices: " << std::endl;
        
        std::vector<const device>::iterator iter2;

        for (iter2 = lUser->DevicesList->begin(); iter2 != lUser->DevicesList->end(); ++iter2) {
            stream << "Device #" << std::endl;
        }
        
        return stream;
    }

    
    
    
};

#endif /* defined(__KomunikatorV2__LocalUser__) */
