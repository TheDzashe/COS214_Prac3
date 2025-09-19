#ifndef USERS_H
#define USERS_H

#include <vector>
#include <string>

class ChatRoom;
class Command;

//colleague
class Users{
    protected:
        std::vector<ChatRoom*> chatRooms; //these are my mediators
        std::string name;
        std::vector<Command*> commandQueue;
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
};

#endif