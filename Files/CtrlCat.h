/**
 * @file CtrlCat.h
 * @brief Concrete mediator class for the CtrlCat chat room
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"

/**
 * @class CtrlCat
 * @brief Concrete mediator implementation for the CtrlCat-themed chat room
 * This class is also the concrete aggregate for the iterator design pattern
 * 
 * This class represents one of the main chat rooms in PetSpace
 */
class CtrlCat: public ChatRoom{
public:
    /**
     * @brief Default constructor
     */
    CtrlCat();
    
    /**
     * @brief Register a new user in the CtrlCat chat room
     * @param user Pointer to the user to be registered
     */
    virtual void registerUser(Users* user);
    
    /**
     * @brief Send a message to all users in the CtrlCat room
     * @param message The message content to be sent
     * @param fromUser Pointer to the user sending the message
     */
    virtual void sendMessage(std::string message, Users* fromUser);
    
    /**
     * @brief Save a message to the CtrlCat chat history
     * @param message The message content to be saved
     * @param fromUser Pointer to the user who sent the message
     */
    virtual void saveMessage(std::string message, Users* fromUser);
    
    /**
     * @brief Remove a user from the CtrlCat chat room
     * @param user Pointer to the user to be removed
     */
    virtual void removeUser(Users* user);
    
    /**
     * @brief Destructor
     */
    virtual ~CtrlCat();

    /**
     * @brief Create an iterator for traversing the CtrlCat chat history
     * @return ChatHistoryIterator* Pointer to a new iterator object
     * @note I feel like I am not supposed to make it general so that these classes can have multiple iterators
     */
    ChatHistoryIterator* createChatHistoryIterator();

    /**
     * @brief Search for messages containing a specific keyword in CtrlCat history
     * @param keyword The search term to look for in message history
     * @return bool True if at least one message contains the keyword, false otherwise
     */
    bool searchMessage(const std::string& keyword);
};

#endif