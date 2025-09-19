
#include <iostream>


#include "Users.h"
#include "ChatRoom.h"
//#include "Command.h"


//!for now before command this is my changed, or should this be in the children??
//remember how the changed() calls notify??
void Users::send(std::string message, ChatRoom* room) {
    if (room != nullptr) {
        std::cout << name << " is sending message to room: " << message << std::endl;
        room->sendMessage(message, this);
    }
}
/* 
1. the reason I chose not to make it pure virtual is so that every user gets standard message sending capabilites
    the code does not need to be duplicated since most users send messages a certain way.
2. specific users who will then need to send users a certain way can then just redefine this function
3. easier to maintain and extend because if I need messages to start looking a certain way I just update here
*/



std::string Users::getName(){
    return name;
}

void Users::joinChatRoom(ChatRoom* chatRoom){
    if (chatRoom != NULL){
        chatRooms.push_back(chatRoom);
    }
}

void Users::addCommand(Command* command) {
    if (command != nullptr) {
        commandQueue.push_back(command);
    }
}




//! check these functions out
// Users::~Users() {
//     for (unsigned int i = 0; i < commandQueue.size(); i++) {
//         delete commandQueue[i];
//     }
// }

// void Users::executeAll() {
//     for (int i = 0; i < commandQueue.size(); i++) {
//         if (commandQueue[i] != nullptr) {
//             commandQueue[i]->execute(); // Execute each command
//         }
//     }
    
//     for (int i = 0; i < commandQueue.size(); i++) {
//         delete commandQueue[i];
//     }
//     commandQueue.clear();
// }