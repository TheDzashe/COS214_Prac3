/**
 * @file ReadState.h
 * @brief Concrete state class representing the Read state in the State design pattern
 * @author Nyashadzashe
 * @date 2025
 */

// ReadState.h
#ifndef READSTATE_H
#define READSTATE_H

#include "MessageState.h"

/**
 * @class ReadState
 * @brief Concrete state representing a message that has been read by the recipient
 * 
 * This class implements the Read state behavior for messages in the PetSpace platform.
 * In this state, messages cannot be edited or deleted, representing their final state in the message lifecycle.
 */
class ReadState : public MessageState {
public:
    /**
     * @brief Handle delivery attempt on an already read message
     * @param context Pointer to the message context
     */
    virtual void handleDelivery(Message* context);
    
    /**
     * @brief Handle read attempt on an already read message
     * @param context Pointer to the message context
     */
    virtual void handleRead(Message* context);

    /**
     * @brief Get the name of this state
     * @return std::string "Read"
     */
    virtual std::string getStatusName();
    
    /**
     * @brief Check if messages in Read state can be edited
     * @return bool False - read messages cannot be edited
     */
    virtual bool canBeEdited();
    
    /**
     * @brief Check if messages in Read state can be deleted
     * @return bool False - read messages cannot be deleted
     */
    virtual bool canBeDeleted();
};

#endif