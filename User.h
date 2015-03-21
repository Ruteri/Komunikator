//
//  User.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

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
    
    bool checkIfHasFriend(User*);
    bool removeFriendFromFriendsList(User*);
    bool removeDeviceFromDevicessList(device*); // POTRZEBUJE ID DEVICE!!!!

    
    
    const std::vector<const User>::iterator getUserListIterator();
    const std::vector<const device>::iterator getDeviceListIterator();
    const std::vector<const std::string>::iterator getMessageIterator();
    
    
    friend std::ostream& getMessages(std::ostream& stream, const User*) {
        return stream;
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const User*) {
        return stream;
    }
};


#endif /* defined(__KomunikatorV2__User__) */
