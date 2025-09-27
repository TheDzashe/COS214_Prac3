/**
 * @file CtrlCat.cpp
 * @brief Implementation of the CtrlCat class
 * @author Nyashadzashe
 * @date 2025
 */

#include "CtrlCat.h"
#include "ChatHistoryIterator.h"

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
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            users.erase(users.begin() + i);
            std::cout << user->getName() << " has left the CtrlCat room." << std::endl;
            break;
        }
    }
}

void CtrlCat::sendMessage(std::string message, Users* fromUser) {
    //we save the message first
    //saveMessage(message, fromUser);
    
    std::cout << "(CtrlCat) Broadcasting message: " << message << std::endl;

    for (size_t i = 0; i < users.size(); i++) {
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


ChatHistoryIterator* CtrlCat::createChatHistoryIterator(){
    //this is a copy of the chat history passed to the iterator
    //! I feel like I do not need to delete these since the vector should handle deletion right?
    return new ChatHistoryIterator(chatHistory);
}

bool CtrlCat::searchMessage(const std::string& keyword) {
    Iterator* iterator = createChatHistoryIterator();
    bool found = false;
    
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        std::string message = iterator->currentItem();
        
        // Simple manual search without npos
        bool containsKeyword = false;
        for (size_t i = 0; i <= message.length() - keyword.length(); i++) {
            if (message.substr(i, keyword.length()) == keyword) {
                containsKeyword = true;
                break;
            }
        }
        
        if (containsKeyword) {
            std::cout << "Found: " << message << std::endl;
            found = true;
        }
    }
    
    delete iterator;
    return found;
}
