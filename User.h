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
#include <iostream>
#include <vector>

class User : public ComSubject
{
    
    std::vector<ComSubject*>* listaPrzyjaciol;
    
    
public:
    User(ComSubject*);
    User(int Id = 0);

    
    bool addFriend(ComSubject*);
    bool removeFriend(ComSubject*);
    
    std::vector<ComSubject*>::const_iterator getIterator();
    
    bool checkIfInFriends(ComSubject*);
    
    
};

#endif /* defined(__KomunikatorV2__User__) */
