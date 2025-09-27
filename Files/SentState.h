/**
 * @file SentState.h
 * @brief Concrete state class representing the Sent state in the State design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef SENTSTATE_H
#define SENTSTATE_H

#include "MessageState.h"

/**
 * @class SentState
 * @brief Concrete state representing a message that has been sent but not yet delivered
 * 
 * This class implements the Sent state behavior for messages in the PetSpace platform.
 * In this state, messages are queued for delivery but cannot be read until they transition
 * to the Delivered state.
 */
class SentState : public MessageState {
public:
    /**
     * @brief Handle delivery transition from Sent to Delivered state
     * @param context Pointer to the message context
     */
    virtual void handleDelivery(Message* context);
    
    /**
     * @brief Handle read attempt on a sent but undelivered message
     * @param context Pointer to the message context
     */
    virtual void handleRead(Message* context);
    
    /**
     * @brief Get the name of this state
     * @return std::string "Sent"
     */
    virtual std::string getStatusName();
    
    /**
     * @brief Check if messages in Sent state can be edited
     * @return bool False - sent messages cannot be edited
     */
    virtual bool canBeEdited();
    
    /**
     * @brief Check if messages in Sent state can be deleted
     * @return bool True - sent messages can be deleted
     */
    virtual bool canBeDeleted();
};

#endif