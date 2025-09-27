#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "Users.h"

//concrete mediator
class Dogorithm: public ChatRoom{
    public:
        Dogorithm();
        virtual void registerUser(Users* user);
        virtual void sendMessage(std::string message, Users* fromUser);
        virtual void saveMessage(std::string message, Users* fromUser);
        virtual void removeUser(Users* user);
        virtual ~Dogorithm();
    
        //I feel like I am not supposed to make it general so that these classes can have multiple iterators
        ChatHistoryIterator* createChatHistoryIterator();

        bool searchMessage(const std::string& keyword);
};

#endif