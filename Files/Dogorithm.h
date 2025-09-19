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
        virtual ~Dogorithm() {};
};

#endif