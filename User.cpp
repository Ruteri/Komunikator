
#include "User.h"

User::User(ComSubject* CS): ComSubject(CS->getID()), listaPrzyjaciol(new std::vector<ComSubject*>) {}
User::User(int Id): ComSubject(Id), listaPrzyjaciol(new std::vector<ComSubject*>) {}

bool User::addFriend(ComSubject* toAdd)
{
    if (checkIfInFriends(toAdd)) return 1;
    
    listaPrzyjaciol->push_back(new ComSubject(toAdd->getID()));
    return 0;
}

bool User::removeFriend(ComSubject* toDel)
{
    std::vector<ComSubject*>::iterator iterator;
    iterator = listaPrzyjaciol->begin();
    for (;iterator!=listaPrzyjaciol->end();++iterator)
    {
        if (*iterator == toDel) {
            listaPrzyjaciol->erase(iterator);
            return 0;
        }
    }
    
    return 1;
}

std::vector<ComSubject*>::const_iterator User::getFriendsListIterator()
{
    return listaPrzyjaciol->cbegin();
}

bool User::checkIfInFriends(ComSubject* toFind)
{
    std::vector<ComSubject*>::iterator iterator;
    iterator = listaPrzyjaciol->begin();
    for (;iterator!=listaPrzyjaciol->end();++iterator)
    {
        if (*iterator == toFind) {
            return true;
        }
    }
    
    return false;

}

std::vector<const Message*>* User::findMessagesWith(ComSubject* toFind)
{
    int i;
    
    std::vector<const Message*>* vect = new std::vector<const Message*>;
    
    for (i = 0; i < MessageListSize(); ++i) {
        if (getMessage(i)->getReciever()->getID() == toFind->getID() || getMessage(i)->getSender()->getID() == toFind->getID()) {
            vect->push_back(getMessage(i));
        }
    }
    
    return vect;
    
}