#ifndef USERS_H
#define USERS_H

#include <vector>
#include <string>

#include "Message.h"

class ChatRoom;
class Command;

//colleague
class Users{
    protected:
        std::vector<ChatRoom*> chatRooms; //these are my mediators
        std::string name;
        std::vector<Command*> commandQueue;
        std::vector<Message*> sentMessages; //part of state design pattern, just for the print outs and stuff
    public:
        Users(std::string n){
            name = n;
        }
        virtual void send(std::string message, ChatRoom* room);
        virtual void receive(std::string message, Users* fromUser, ChatRoom* room)=0;

        void addCommand(Command* command);
        void executeAll();
        virtual ~Users();

        std::string getName();
        void joinChatRoom(ChatRoom* chatRoom);

        //void displayAllMessageStates();
};

#endif