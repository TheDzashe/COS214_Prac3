
#ifndef SENTSTATE_H
#define SENTSTATE_H

#include "MessageState.h"

class SentState : public MessageState {
public:
    virtual void handleDelivery(Message* context);
    virtual void handleRead(Message* context);
    
    
    virtual std::string getStatusName();
    virtual bool canBeEdited();
    virtual bool canBeDeleted();
};

#endif