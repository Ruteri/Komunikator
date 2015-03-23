#ifndef MESSAGE_H
#define MESSAGE_H

#include "ComSubject.h"
#include <string>

class ComSubject;

class Message{
	private:
		ComSubject* Sender;
		ComSubject* Reciever;
		std::string Text;
	public:
		Message(ComSubject* sender, ComSubject* reciever, std::string text);
		const ComSubject* getSender();
		ComSubject* getReciever();
		std::string getText();
};

#endif