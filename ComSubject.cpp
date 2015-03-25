#include "ComSubject.h"

ComSubject::ComSubject(int id){
	ID = id;
}

int ComSubject::getID() const{
	return ID;
}

void ComSubject::recieveMessage(Message msg){
	//MessageList.push_back(&msg);
	Message* tmp = new Message(msg.getSender(),this,msg.getText());
	MessageList.push_back(tmp);
}

void ComSubject::recieveMessage(ComSubject* sender, std::string text){
	Message* tmp = new Message(sender,this,text);
	MessageList.push_back(tmp);
}

void ComSubject::sendMessage(ComSubject* reciever, std::string text){
	Message* tmp = new Message(this,reciever,text);
	MessageList.push_back(tmp);
	reciever->recieveMessage(this, text);
}

void ComSubject::removeMessage(int msgIndex){
	std::vector<Message*>::iterator ind = MessageList.begin() + msgIndex;
	delete (*(ind));
	MessageList.erase(ind);
}
/*
std::vector<Message*>::iterator ComSubject::getMessageIterator(){
	return MessageList.begin();
}
*/
const Message* ComSubject::getMessage(int at){
	return MessageList[at];
}

int ComSubject::MessageListSize(){
	return MessageList.size();
}