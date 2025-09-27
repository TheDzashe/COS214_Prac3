/**
 * @file Message.h
 * @brief Context class in the State design pattern for message lifecycle management
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include "MessageState.h"
#include <string>

/**
 * @class Message
 * @brief Context class that manages the state of a message in the State design pattern
 * 
 * This class represents a message in the PetSpace platform and manages its lifecycle
 * states (Sent, Delivered, Read) using the State pattern. The Message class delegates
 * state-specific behavior to the current MessageState object.
 */
class Message {
private:
    std::string content;     ///< The content of the message
    std::string sender;      ///< The name of the message sender
    MessageState* currentState; ///< Pointer to the current state object

public:
    /**
     * @brief Constructor that creates a new message with Sent state
     * @param msg The content of the message
     * @param senderName The name of the sender
     */
    Message(const std::string& msg, const std::string& senderName);
    
    /**
     * @brief Destructor that cleans up the current state object
     */
    ~Message(){
        delete currentState;
    };
    
    /**
     * @brief Transition the message to Delivered state
     */
    void deliver();
    
    /**
     * @brief Transition the message to Read state
     */
    void read();

    //the concrete states will change the contexts state
    /**
     * @brief Change the current state of the message
     * @param newState Pointer to the new state object
     * @note The concrete states will change the context's state
     */
    void setState(MessageState* newState);

    /**
     * @brief Get the current status of the message
     * @return std::string The name of the current state
     */
    std::string getStatus();
    
    /**
     * @brief Get the message content
     * @return std::string The content of the message
     */
    std::string getContent();
    
    /**
     * @brief Get the sender's name
     * @return std::string The name of the sender
     */
    std::string getSender();

    /**
     * @brief Check if the message can be edited in its current state
     * @return bool True if editable, false otherwise
     */
    bool canEdit();
    
    /**
     * @brief Check if the message can be deleted in its current state
     * @return bool True if deletable, false otherwise
     */
    bool canDelete();
    
    /**
     * @brief Display message information including status and permissions
     */
    void displayInfo();
};

#endif