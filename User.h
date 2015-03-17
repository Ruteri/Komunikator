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

class User : public ComSubject
{
    std::vector<User> friendsList;
    std::vector<device> devicesList;
    
    // u kogo lista wiadomosci?
    
    char* IP;
    
public:
    User(Serwer* serwer = nullptr);
    ~User();
    
    
    int getIDFromSerwer(Serwer*);
    
    bool askServerForPermissionToAddNewFriendAndIfSoAdd(User*, Serwer*);
    bool checkIfHasFriend(User*);
    
    
    
    friend std::ostream& operator<<(std::ostream& stream, const User*) {
        return stream;
    }
};


#endif /* defined(__KomunikatorV2__User__) */
