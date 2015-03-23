#include "Message.h"

Message::Message(ComSubject* sender, ComSubject* reciever, std::string text){
	Sender = sender;
	Reciever = reciever;
	Text = text;
}

ComSubject* Message::getReciever(){
	return Reciever;
}

const ComSubject* Message::getSender(){
	return Sender;
}

std::string Message::getText(){
	return Text;
}