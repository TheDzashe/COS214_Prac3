#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"

class CtrlCat: public ChatRoom{
    public:
        CtrlCat();
        virtual void registerUser(Users* user);
        virtual void sendMessage(std::string message, Users* fromUser);
        virtual void saveMessage(std::string message, Users* fromUser);
        virtual void removeUser(Users* user);
        virtual ~CtrlCat();

        //I feel like I am not supposed to make it general so that these classes can have multiple iterators
        ChatHistoryIterator* createChatHistoryIterator();

        bool searchMessage(const std::string& keyword);
};

#endif