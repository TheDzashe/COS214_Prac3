#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>

class Users; 

//mediator
class ChatRoom{
    protected:
        std::vector<Users*> users;
        std::vector<std::string> chatHistory; //the String* from the spec just means that a collection of Strings
    public:
        ChatRoom();
        virtual void registerUser(Users* user) = 0;
        virtual void sendMessage(std::string message, Users* fromUser) =0; //this is basically the notify
        virtual void saveMessage(std::string message, Users* fromUser) = 0;
        virtual void removeUser(Users* user)=0;
        virtual ~ChatRoom();
        
};


#endif