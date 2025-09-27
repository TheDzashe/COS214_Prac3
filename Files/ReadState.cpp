/**
 * @file ReadState.cpp
 * @brief Implementation of the ReadState class
 * @author Nyashadzashe
 * @date 2025
 */

#include "ReadState.h"
#include <iostream>

void ReadState::handleDelivery(Message* context) {
    std::cout << "ReadState: Message already delivered and read." << std::endl;
}

void ReadState::handleRead(Message* context) {
    std::cout << "ReadState: Message already read." << std::endl;
}

std::string ReadState::getStatusName()  {
    return "Read";
}

bool ReadState::canBeEdited()  {
    return false;
}

bool ReadState::canBeDeleted()  {
    return false; //I want read messages to not be able to be deleted
}