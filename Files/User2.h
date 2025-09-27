#ifndef USER2_H
#define USER2_H

#include <vector>
#include <string>

#include "Users.h"

class Command;

//concrete colleague
class User2: public Users{
    public:
        //User2(ChatRoom* chatRooms, std::string name);
        User2(std::string name);
        //virtual void send(std::string message, ChatRoom* room);
        virtual void receive(std::string message, Users* fromUser, ChatRoom* room);
        virtual ~User2() {};
};

#endif