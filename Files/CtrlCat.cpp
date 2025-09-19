#include "CtrlCat.h"

#include <iostream>

CtrlCat::CtrlCat(){
    //nothing
}

void CtrlCat::registerUser(Users* user) {

    //trying to avoid NULL pointers and stuff
    if (user != NULL) {
        users.push_back(user);
        std::cout << user->getName() << " has joined the CtrlCat room." << std::endl;
    }
}

void CtrlCat::removeUser(Users* user) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            users.erase(users.begin() + i);
            std::cout << user->getName() << " has left the CtrlCat room." << std::endl;
            break;
        }
    }
}

void CtrlCat::sendMessage(std::string message, Users* fromUser) {
    //we save the message first
    saveMessage(message, fromUser);
    
    std::cout << "(CtrlCat) Broadcasting message: " << message << std::endl;

    for (int i = 0; i < users.size(); i++) {
        //so that the message does not go back to the sender
        if (users[i] != fromUser) {
            users[i]->receive(message, fromUser, this);
        }
    }
}


void CtrlCat::saveMessage(std::string message, Users* fromUser) {

    //want the message to have the senders name 
    std::string editedMsg = "[CtrlCat] " + fromUser->getName() + ": " + message;

    //the message will also be saved to the chatHistory
    chatHistory.push_back(editedMsg);
    
    //doing this for debugging
    std::cout << "(Log saved) " << editedMsg << std::endl;
}

CtrlCat::~CtrlCat() {
    //feel like for now it doesn't really do anything cause it's not really responsible for any poinnters like that??
}
