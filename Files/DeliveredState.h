#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

#include "MessageState.h"

class DeliveredState : public MessageState {
public:
    void handleDelivery(Message* context);
    void handleRead(Message* context);

    std::string getStatusName(); //this will be so that the specific state has a name
    bool canBeEdited();
    bool canBeDeleted();
};

#endif