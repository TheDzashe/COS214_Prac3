#ifndef MESSAGESTATE_H
#define MESSAGESTATE_H

#include <string>

class Message;  

//! concrete states applying variable criteria
//this is the state in the state design pattern
class MessageState {
public:
    virtual ~MessageState() {};
    
    //would consider these my handle()
    virtual void handleDelivery(Message* context) = 0;
    virtual void handleRead(Message* context) = 0;
    
    //these are more about what can be done with a specific state
    virtual std::string getStatusName()=0;
    virtual bool canBeEdited()=0;
    virtual bool canBeDeleted()=0;
};

#endif


/*

Reasonings:
    1. Yes the intent has been demonstrated
    2. Behavioural, it manages the lifecycle states of the messages
    3. It allows users to know more information about the messages, they sent. 
        - Message states can change without affecting the Users, and new States can be added without affecting existing code 
    4. I could easily add more message states such as failedToSend or EditedState, and this would be easy because of the use of the design pattern
    
*/