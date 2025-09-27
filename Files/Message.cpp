/**
 * @file Message.cpp
 * @brief Implementation of the Message class
 * @author Nyashadzashe
 * @date 2025
 */

#include "Message.h"
#include "SentState.h"
#include <iostream>

Message::Message(const std::string& msg, const std::string& senderName){
        content = msg;
        sender = senderName;
        currentState = new SentState();
}

void Message::setState(MessageState* newState) {
    if (currentState == newState) {
        // Same pointer - delete the redundant new state
        delete newState;
        return;
    }
    
    if (currentState != NULL) {
        delete currentState;
    }
    currentState = newState;
}

void Message::deliver() {
    currentState->handleDelivery(this); //state handles everything
}

void Message::read() {
    currentState->handleRead(this);
}

std::string Message::getStatus(){
    return currentState->getStatusName();
}

std::string Message::getContent(){
    return content;
}

std::string Message::getSender(){
    return sender;
}

bool Message::canEdit(){
    return currentState->canBeEdited();
}

bool Message::canDelete(){
    return currentState->canBeDeleted();
}

void Message::displayInfo() {
    std::cout << "Message from " << sender << ": " << content << " [Status: " << getStatus() << ", Editable: " << (canEdit() ? "Yes" : "No") << ", Deletable: " << (canDelete() ? "Yes" : "No") << "]" << std::endl;
}

//! implement the other methods