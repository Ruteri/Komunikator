
#include "User.h"

User::User(ComSubject* CS): ComSubject(CS->getID()), listaPrzyjaciol(new std::vector<ComSubject*>) {}
User::User(int Id): ComSubject(Id), listaPrzyjaciol(new std::vector<ComSubject*>) {}

bool User::addFriend(ComSubject* toAdd)
{
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

std::vector<ComSubject*>::const_iterator User::getIterator()
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
            return 0;
        }
    }
    
    return 1;

}
