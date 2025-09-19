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
};

#endif