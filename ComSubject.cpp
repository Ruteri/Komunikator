#include "ComSubject.h"

ComSubject::ComSubject(int id){
	ID = id;
}

const int ComSubject::getID(){
	return ID;
}

void ComSubject::recieveMessage(ComSubject* sender, std::string text){
	Message* tmp = new Message(sender,this,text);
	MessageList.push_back(tmp);
}

void ComSubject::sendMessage(ComSubject* reciever, std::string text){
	reciever->recieveMessage(this, text);
}