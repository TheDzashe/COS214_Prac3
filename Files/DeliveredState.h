/**
 * @file DeliveredState.h
 * @brief Concrete state class representing the Delivered state in the State design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

#include "MessageState.h"

/**
 * @class DeliveredState
 * @brief Concrete state representing a message that has been delivered but not yet read
 * 
 * This class implements the Delivered state behavior for messages in the PetSpace platform.
 * In this state, messages are available to be read by the recipient but have not yet been
 * viewed. This is an intermediate state between Sent and Read.
 */
class DeliveredState : public MessageState {
public:
    /**
     * @brief Handle delivery attempt on an already delivered message
     * @param context Pointer to the message context
     */
    void handleDelivery(Message* context);
    
    /**
     * @brief Handle read transition from Delivered to Read state
     * @param context Pointer to the message context
     */
    void handleRead(Message* context);

    /**
     * @brief Get the name of this state
     * @return std::string "Delivered"
     * @note this will be so that the specific state has a name
     */
    std::string getStatusName(); //this will be so that the specific state has a name
    
    /**
     * @brief Check if messages in Delivered state can be edited
     * @return bool False - delivered messages cannot be edited
     */
    bool canBeEdited();
    
    /**
     * @brief Check if messages in Delivered state can be deleted
     * @return bool True - delivered messages can be deleted
     */
    bool canBeDeleted();
};

#endif