#ifndef MESSAGE_H
#define MESSAGE_H

#include "MessageState.h"
#include <string>

class Message {
private:
    std::string content;
    std::string sender;
    MessageState* currentState;

public:
    Message(const std::string& msg, const std::string& senderName);
    ~Message(){
        delete currentState;
    };
    
    void deliver();
    void read();

    //the concrete states will change the contexts state
    void setState(MessageState* newState);

    std::string getStatus();
    std::string getContent();
    std::string getSender();

    bool canEdit();
    bool canDelete();
    void displayInfo();
};

#endif