/**
 * @file ChatRoom.h
 * @brief Mediator class for handling chat room operations in PetSpace
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>
#include "Iterator.h"

class ChatHistoryIterator;
class Users; 

/**
 * @class ChatRoom
 * @brief Abstract mediator class that coordinates communication between users
 * 
 * This class serves multiple roles in the design patterns:
 * - **Mediator** in the Mediator pattern: Coordinates communication between Users
 * - **Receiver** in the Command pattern: Performs the actual operations requested by commands
 * - **Aggregate** in the Iterator pattern: Provides access to chat history via iterators
 * 
 * Concrete implementations like CtrlCat and Dogorithm manage user interactions and message history.
 */
class ChatRoom{
protected:
    std::vector<Users*> users;           ///< List of users currently registered in the chat room
    std::vector<std::string> chatHistory; ///< History of all messages sent in this chat room
    //!I want this to be used for the iterator design pattern, check out what chat said

public:
    /**
     * @brief Default constructor
     */
    ChatRoom(){};
    
    /**
     * @brief Register a new user in the chat room
     * @param user Pointer to the user to be registered
     */
    virtual void registerUser(Users* user)=0;
    
    /**
     * @brief Send a message to all users in the chat room
     * @param message The message content to be sent
     * @param fromUser Pointer to the user sending the message
     * @note This is basically the notify function in the Mediator pattern
     */
    virtual void sendMessage(std::string message, Users* fromUser)=0; //this is basically the notify
    
    /**
     * @brief Save a message to the chat history
     * @param message The message content to be saved
     * @param fromUser Pointer to the user who sent the message
     */
    virtual void saveMessage(std::string message, Users* fromUser)=0;
    
    /**
     * @brief Remove a user from the chat room
     * @param user Pointer to the user to be removed
     */
    virtual void removeUser(Users* user)=0;
    
    /**
     * @brief Virtual destructor
     */
    virtual ~ChatRoom(){};

    /**
     * @brief Create an iterator for traversing the chat history
     * @return ChatHistoryIterator* Pointer to a new iterator object
     * @note I feel like I am not supposed to make it general so that these classes can have multiple iterators
     */
    virtual ChatHistoryIterator* createChatHistoryIterator()=0;

    /**
     * @brief Search for messages containing a specific keyword
     * @param keyword The search term to look for in message history
     * @return bool True if at least one message contains the keyword, false otherwise
     */
    virtual bool searchMessage(const std::string& keyword)=0;
};

#endif