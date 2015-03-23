#ifndef COMSUBJECT_H
#define COMSUBJECT_H

#include "Message.h"
#include <vector>
#include <string>

class Message;

class ComSubject{
	private:
		int ID;
		std::vector <Message*> MessageList;
	public:
		ComSubject(int id);

		const int getID();
		
		void recieveMessage(ComSubject* sender, std::string text);
		void sendMessage(ComSubject* reciever, std::string text);

};
#endif