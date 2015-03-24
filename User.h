//
//  User.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//
/*
#ifndef __KomunikatorV2__User__
#define __KomunikatorV2__User__

#include "ComSubject.h"
#include "device.h"
#include <ostream>
#include <vector>
#include "Serwer.h"

class Serwer;

class User : public ComSubject
{
    // Te będą przeniesione do innej klasy
    std::vector<User>* friendsList;
    std::vector<device>* devicesList;
    std::vector<User>::iterator friendIter;
    std::vector<device>::iterator devIter;

    
    std::vector<std::string>* messList;
    
    char* IP;
    int ID;
    
public:
    User(Serwer* serwer = nullptr);
        
    bool askServerForPermissionToAddNewFriendAndIfSoAdd(User*, Serwer*);
    
    // Potem do innej klasy
    bool checkIfHasFriend(User*);
    bool removeFriendFromFriendsList(User*);
    bool removeDeviceFromDevicessList(device*); // POTRZEBUJE ID DEVICE!!!!
    
    //
    std::vector<const User>::iterator getUserListIterator();
    std::vector<const device>::iterator getDeviceListIterator();
    std::vector<const std::string>::iterator getMessageIterator();
    
    
    friend std::ostream& getMessages(std::ostream& stream, const User*) {
        return stream;
    }
    
    friend std::ostream& operator<<(std::ostream& stream, User* user) {
        stream << "Friends: " << std::endl;

        for (user->friendIter = user->friendsList->begin(); user->friendIter != user->friendsList->end(); ++user->friendIter) {
            stream << "ID: " << user->friendIter->ID << std::endl;
        }
        
        stream << std::endl << "Devices: " << std::endl;

        for (user->devIter = user->devicesList->begin(); user->devIter != user->devicesList->end(); ++user->devIter) {
            stream << "Device #" << std::endl;
        }
 
        
        
        
        return stream;
    }
};


#endif /* defined(__KomunikatorV2__User__) */
