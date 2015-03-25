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

        int getID() const;
		void recieveMessage(Message msg);
		void recieveMessage(ComSubject* sender, std::string text);
		void sendMessage(ComSubject* reciever, std::string text);
		void removeMessage(int msgIndex);
		//std::vector<Message*>::iterator getMessageIterator();
		const Message* getMessage(int at);
		int MessageListSize();

		friend std::ostream& operator<<(std::ostream& stream, const ComSubject*) {
			/*for(int i = 0; i<MessageListSize(); i++){

			}*/
			return stream;
		}
};
#endif