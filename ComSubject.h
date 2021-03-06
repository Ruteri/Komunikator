#ifndef COMSUBJECT_H
#define COMSUBJECT_H

#include "Message.h"
#include <vector>
#include <string>
#include <iostream>

class Message;

class ComSubject{
	private:
		int ID;
		std::vector <Message*> MessageList;
	public:
		ComSubject(int id);

        int getID() const;
		void recieveMessage(Message msg);
		void recieveMessage(ComSubject* sender, std::string text);
		void sendMessage(ComSubject* reciever, std::string text);
		void removeMessage(int msgIndex);
		//std::vector<Message*>::iterator getMessageIterator();
		const Message* getMessage(int at) const;
		int MessageListSize() const;

		void operator<<(std::ostream& stream);
};
#endif