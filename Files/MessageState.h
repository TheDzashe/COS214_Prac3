/**
 * @file MessageState.h
 * @brief Abstract state class in the State design pattern for message lifecycle states
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef MESSAGESTATE_H
#define MESSAGESTATE_H

#include <string>

class Message;  

//! concrete states applying variable criteria
//this is the state in the state design pattern
/**
 * @class MessageState
 * @brief Abstract State class that defines the interface for message lifecycle states
 * 
 * This class represents the State in the State design pattern, defining the interface
 * for all concrete message states (Sent, Delivered, Read). Each concrete state
 * implements state-specific behavior for message delivery, reading, and permissions.
 */
class MessageState {
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~MessageState() {};
    
    //would consider these my handle()
    /**
     * @brief Handle the delivery transition for a message
     * @param context Pointer to the message context
     * @note Would consider these my handle() methods
     */
    virtual void handleDelivery(Message* context) = 0;
    
    /**
     * @brief Handle the read transition for a message
     * @param context Pointer to the message context
     */
    virtual void handleRead(Message* context) = 0;
    
    //these are more about what can be done with a specific state
    /**
     * @brief Get the name of the current state
     * @return std::string The name of the state
     * @note These are more about what can be done with a specific state
     */
    virtual std::string getStatusName()=0;
    
    /**
     * @brief Check if messages in this state can be edited
     * @return bool True if editable, false otherwise
     */
    virtual bool canBeEdited()=0;
    
    /**
     * @brief Check if messages in this state can be deleted
     * @return bool True if deletable, false otherwise
     */
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