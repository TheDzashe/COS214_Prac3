/**
 * @file SentState.cpp
 * @brief Implementation of the SentState class
 * @author Nyashadzashe
 * @date 2025
 */

#include "SentState.h"
#include "DeliveredState.h"
#include "Message.h"
#include <iostream>

void SentState::handleDelivery(Message* context) {
    std::cout << "SentState: Processing delivery request..." << std::endl;

    context->setState(new DeliveredState());
    std::cout << "Message delivered." <<std::endl;
}

void SentState::handleRead(Message* context) {
    std::cout << "SentState: Cannot read undelivered message." << std::endl;
}

std::string SentState::getStatusName()  {
    return "Sent";
}

bool SentState::canBeEdited()  {
    return false;
}

bool SentState::canBeDeleted()  {
    return true;
}