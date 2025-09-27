#include "DeliveredState.h"
#include "ReadState.h"
#include "Message.h"
#include <iostream>

void DeliveredState::handleDelivery(Message* context) {
    std::cout << "DeliveredState: Message already delivered." << std::endl;
}

void DeliveredState::handleRead(Message* context) {
    std::cout << "DeliveredState: Processing read request..." << std::endl;
    
    context->setState(new ReadState());
    std::cout << "Message read." << std::endl;
}

std::string DeliveredState::getStatusName()  {
    return "Delivered";
}

bool DeliveredState::canBeEdited()  {
    return false;
}

bool DeliveredState::canBeDeleted()  {
    return true;
}