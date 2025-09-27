#ifndef USER3_H
#define USER3_H

#include <vector>
#include <string>

#include "Users.h"

class Command;

//concrete colleague
class User3: public Users{
    public:
        //User3(ChatRoom* chatRooms, std::string name);
        User3(std::string name);
        //virtual void send(std::string message, ChatRoom* room);
        virtual void receive(std::string message, Users* fromUser, ChatRoom* room);
        virtual ~User3() {};
};

#endif