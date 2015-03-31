#include "Message.h"

Message::Message(ComSubject* sender, ComSubject* reciever, std::string text){
	Sender = sender;
	Reciever = reciever;
	Text = text;
}

const ComSubject* Message::getReciever() const{
	return Reciever;
}

const ComSubject* Message::getSender() const{
	return Sender;
}

const std::string Message::getText() const{
	return Text;
}