//
//  FriendUser.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#ifndef __KomunikatorV2__FriendUser__
#define __KomunikatorV2__FriendUser__
#include "BaseUser.h"
#include <vector>
#include <map>
#include "Message.h"
#include <iostream>
#include <string>

class FriendUser : public BaseUser
{
    std::vector<const Message>* lastMessagesList;
    
    
public:
    FriendUser(int Id, std::string nick): BaseUser(Id, nick), lastMessagesList(nullptr) { lastMessagesList = new std::vector<const Message>(); }
    
    inline bool pushMessage(const Message& messageToPush) const
    {
        lastMessagesList->push_back(messageToPush);
        return 0;
    }
    
    inline std::vector<const Message>::reverse_iterator getIterator() const
    {
        return lastMessagesList->rend();
    }
    
    friend std::ostream& operator<<(std::ostream& stream, FriendUser& user) {
        stream << user.getID();
        return stream;
    }
    
};


#endif /* defined(__KomunikatorV2__FriendUser__) */
