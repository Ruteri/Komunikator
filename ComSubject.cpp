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

std::vector<Message*>::iterator ComSubject::getMessageIterator(){
	return MessageList.begin();
}

const Message* ComSubject::getMessage(int at){
	return MessageList[at];
}

int ComSubject::MessageListSize(){
	return MessageList.size();
}