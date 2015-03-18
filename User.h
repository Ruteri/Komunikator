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
    std::vector<device> devicesList; // tu nie w com
    
    // u kogo lista wiadomosci?
    
    char* IP;
    
public:
    User(int ID); // tylko na poczatek
    User(Serwer* serwer = nullptr); // rejestracja
    User(char* registeredUsername, char* registeredPassword); // logowanie - moze
    ~User();
    
        
    bool askServerForPermissionToAddNewFriendAndIfSoAdd(User*, Serwer*);
    
    bool checkIfHasFriend(User*);
    bool removeFriendFromFriendsList(User*);
    
    // const iterator, dodawanie przyjaciol,usuwanie przyjaciol
    
    const std::vector<User>::iterator userListIterator;
    const std::vector<device>::iterator deviceListIterator;

    
    friend std::ostream& operator<<(std::ostream& stream, const User*) {
        return stream;
    }
};


#endif /* defined(__KomunikatorV2__User__) */
