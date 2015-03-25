//
//  User.h
//  KomunikatorV2
//
//  Created by Konto Mateusza on 17.03.2015.
//  Copyright (c) 2015 Mateusz. All rights reserv.
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
    
    std::vector<ComSubject*>::const_iterator getFriendsListIterator();
    
    bool checkIfInFriends(ComSubject*);
    
    std::vector<const Message*>* findMessagesWith(ComSubject*);
    
    friend std::ostream& operator<<(std::ostream& stream, User& user)
    {
        
        auto iterator = user.listaPrzyjaciol->begin();
       
        stream << "User with ID: " << user.getID() << std::endl << "Friends: " << std::endl;
        for (;iterator != user.listaPrzyjaciol->end() ; ++iterator) {
            stream << "ID: " << (*iterator)->getID() << std::endl << "Messages: " << std::endl;
            auto listaWiadomosci = user.findMessagesWith(*iterator);
            for (int i = 0; i < listaWiadomosci->size(); ++i) {
                stream << (*listaWiadomosci)[i]->getText() << std::endl;
            }
            stream << std::endl;
        }
        
        return stream;
    }
    
};

#endif /* defined(__KomunikatorV2__User__) */
