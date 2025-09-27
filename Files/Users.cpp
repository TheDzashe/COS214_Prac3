/**
 * @file Users.cpp
 * @brief Implementation of the User class
 * @author Nyashadzashe
 * @date 2025
 */


#include <iostream>


#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "Message.h"


//!for now before command this is my changed, or should this be in the children??
//remember how the changed() calls notify??
void Users::send(std::string message, ChatRoom* room) {
    // if (room != nullptr) {
    //     std::cout << name << " is sending message to room: " << message << std::endl;
    //     room->sendMessage(message, this);
    // }


    //should it be that when a message gets sent it calls executeAll()
    //then the execute all executes whatever is in the queue??
    if(room != NULL){
        if (room != NULL) {

            //state pattern
            Message* messageState = new Message(message, this->name);
            sentMessages.push_back(messageState);

            std::cout << "**State Pattern: Message Created" << std::endl;
            messageState->displayInfo();


            //command pattern
            //creates the commands directly
            commandQueue.push_back(new SendMessageCommand(room, message, this));
            commandQueue.push_back(new LogMessageCommand(room, message, this));
            
            executeAll();

            //simulate delivery and reading
            std::cout << "**State Pattern: Simulating Delivery" << std::endl;
            messageState->deliver();
            messageState->displayInfo();
            
            std::cout << "**State Pattern: Simulating Reading" << std::endl;
            messageState->read();
            messageState->displayInfo();
        }
    }
}
/* 
1. the reason I chose not to make it pure virtual is so that every user gets standard message sending capabilites
    the code does not need to be duplicated since most users send messages a certain way.
2. specific users who will then need to send users a certain way can then just redefine this function
3. easier to maintain and extend because if I need messages to start looking a certain way I just update here
*/


void Users::executeAll() {
    for (size_t i = 0; i < commandQueue.size(); i++) {
        if (commandQueue[i] != NULL) {
            commandQueue[i]->execute(); //execute each command
        }
    }
    
    for (size_t i = 0; i < commandQueue.size(); i++) {
        delete commandQueue[i];
    }
    commandQueue.clear();
}



std::string Users::getName(){
    return name;
}

void Users::joinChatRoom(ChatRoom* chatRoom){
    if (chatRoom != NULL){
        chatRooms.push_back(chatRoom);
    }
    chatRoom->registerUser(this); //! mhhhmmm I am not really sure about this ngl
}

void Users::addCommand(Command* command) {
    if (command != NULL) {
        commandQueue.push_back(command);
    }
}

Users::~Users() {
    for (size_t i = 0; i < commandQueue.size(); i++) {
        //so that the commands that are not deleted are then deleted
        if (commandQueue[i] != NULL) {
            delete commandQueue[i];
        }
    }
    commandQueue.clear();


    for (size_t i = 0; i < sentMessages.size(); i++) {
        if (sentMessages[i] != NULL) {
            delete sentMessages[i];
        }
    }
    sentMessages.clear();
}

//!only for the demo
// void Users::displayAllMessageStates() {
//     std::cout << "Message States for " << name << " =" << std::endl;

//     for(size_t i=0; i<sentMessages.size(); ++i){
//         if(sentMessages[i]){
//             sentMessages[i]->displayInfo();
//         }
//     }
// }




//if i wanted to implement a search of the messages
// Message* Users::findMessage(const std::string& content) {
//     for (Message* msg : sentMessages) {
//         if (msg->getContent() == content) {
//             return msg;
//         }
//     }
//     return nullptr;
// }

