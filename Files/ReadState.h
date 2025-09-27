// ReadState.h
#ifndef READSTATE_H
#define READSTATE_H

#include "MessageState.h"

class ReadState : public MessageState {
public:
    virtual void handleDelivery(Message* context);
    virtual void handleRead(Message* context);

    
    virtual std::string getStatusName();
    virtual bool canBeEdited();
    virtual bool canBeDeleted();
};

#endif