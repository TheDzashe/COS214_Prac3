#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class ChatRoom;
class Users;

class Command{
    protected:
        ChatRoom* room;
        std::string message;
        Users* fromUser;
    public:
        virtual void execute()=0;
        Command(ChatRoom* rm, std::string msg, Users* fromU){
            room = rm;
            message = msg;
            fromUser = fromU;
        };
        Command();
        virtual ~Command(){};
};

#endif