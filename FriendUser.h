//
//  FriendUser.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 23.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserved.
//

#include "BaseUser.h"
#include <vector>
#include "Message.h"
#include <iostream>
#include <string>

#ifndef __KomunikatorV2__FriendUser__
#define __KomunikatorV2__FriendUser__

class FriendUser
{
    std::vector<Message>* messagesReceivedList;
    std::vector<Message>* messagesSentList;

    int ID;
    
public:
    FriendUser(const int& Id = 0): ID(Id), messagesReceivedList(nullptr), messagesSentList(nullptr) { messagesSentList = new std::vector<Message>(); messagesReceivedList = new std::vector<Message>; }
    
    inline bool messageSent(Message messageToPush) const
    {
        messagesSentList->push_back(messageToPush);
        return 0;
    }
    inline bool messageReceived(Message messageToPush) const
    {
        messagesReceivedList->push_back(messageToPush);
        (*messagesReceivedList)[messagesReceivedList->size()] = messageToPush;
        return 0;
    }

    int getID() {return ID;}
    
    inline std::vector<Message>::reverse_iterator getSIterator()
    {
        return messagesSentList->rend();
    }
    inline std::vector<Message>::reverse_iterator getRIterator()
    {
        return messagesReceivedList->rend();
    }

    
    friend std::ostream& operator<<(std::ostream& stream, FriendUser& user) {
        stream << user.getID();
        return stream;
    }
    
};


#endif /* defined(__KomunikatorV2__FriendUser__) */
