//
//  Serwer.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __KomunikatorV2__Serwer__
#define __KomunikatorV2__Serwer__
#include "ComSubject.h"
#include "Message.h"
#include <vector>

class Serwer
{
    int currentID;
    
    //std::vector<LocalUser*>* UserList;
    
public:
    Serwer(): currentID(0) {}// UserList = new std::vector<LocalUser*>(); }
    
    bool addToFriendsList(ComSubject*, ComSubject*);
    int giveIdToNewUser();
    
    
    bool processMessage(Message);
    
};


#endif /* defined(__KomunikatorV2__Serwer__) */
