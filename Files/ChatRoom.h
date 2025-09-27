#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>

#include "Iterator.h"

class ChatHistoryIterator;
class Users; 

//mediator
class ChatRoom{
    protected:
        std::vector<Users*> users;
        std::vector<std::string> chatHistory; 
        //!I want this to be used for the iterator design pattern, check out what chat said
    public:
        ChatRoom(){};
        virtual void registerUser(Users* user)=0;
        virtual void sendMessage(std::string message, Users* fromUser)=0; //this is basically the notify
        virtual void saveMessage(std::string message, Users* fromUser)=0;
        virtual void removeUser(Users* user)=0;
        virtual ~ChatRoom(){};

        //I feel like I am not supposed to make it general so that these classes can have multiple iterators
        virtual ChatHistoryIterator* createChatHistoryIterator()=0;

        virtual bool searchMessage(const std::string& keyword)=0;
};


#endif