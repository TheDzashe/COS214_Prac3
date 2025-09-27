#ifndef USER1_H
#define USER1_H

#include <vector>
#include <string>

#include "Users.h"

class Command;

//concrete colleague
class User1: public Users{
    public:
        //User1(ChatRoom* chatRooms, std::string name);
        User1(std::string name);
        //virtual void send(std::string message, ChatRoom* room);
        virtual void receive(std::string message, Users* fromUser, ChatRoom* room);
        virtual ~User1() {};
};

#endif