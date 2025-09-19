#include "Dogorithm.h"
#include <iostream>

Dogorithm::Dogorithm(){
    //nothing
}

void Dogorithm::registerUser(Users* user) {

    //trying to avoid NULL pointers and stuff
    if (user != NULL) {
        users.push_back(user);
        std::cout << user->getName() << " has joined the Dogorithm room." << std::endl;
    }
}

void Dogorithm::removeUser(Users* user) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            users.erase(users.begin() + i);
            std::cout << user->getName() << " has left the Dogorithm room." << std::endl;
            break;
        }
    }
}

//notice how the notify of the mediator calls the get of the colleague
void Dogorithm::sendMessage(std::string message, Users* fromUser) {
    //we save the message first
    saveMessage(message, fromUser);
    
    std::cout << "(Dogorithm) Broadcasting message: " << message << std::endl;

    for (int i = 0; i < users.size(); i++) {
        //so that the message does not go back to the sender
        if (users[i] != fromUser) {
            users[i]->receive(message, fromUser, this);
        }
    }
}


void Dogorithm::saveMessage(std::string message, Users* fromUser) {

    //want the message to have the senders name 
    std::string editedMsg = "[Dogorithm] " + fromUser->getName() + ": " + message;

    //the message will also be saved to the chatHistory
    chatHistory.push_back(editedMsg);
    
    //doing this for debugging
    std::cout << "(Log saved) " << editedMsg << std::endl;
}

Dogorithm::~Dogorithm() {
    //feel like for now it doesn't really do anything cause it's not really responsible for any poinnters like that??
}
