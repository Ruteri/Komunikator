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
		Message(const ComSubject* sender, const ComSubject* reciever, const std::string text){
			Sender = const_cast <ComSubject*> (sender);
			Reciever = const_cast <ComSubject*> (reciever);
			Text=text;
		}
		const ComSubject* getSender();
		const ComSubject* getReciever();
		const std::string getText() const;
};

#endif