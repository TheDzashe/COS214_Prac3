/**
 * @file User1.h
 * @brief Concrete colleague class representing User1 in the mediator design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef USER1_H
#define USER1_H

#include <vector>
#include <string>
#include "Users.h"

class Command;

/**
 * @class User1
 * @brief Concrete colleague implementation representing a specific user in PetSpace
 * 
 * This class represents one of the concrete users in the system that can participate in chat rooms and send/receive messages through the mediator.
 */
class User1: public Users{
public:
    /**
     * @brief Constructor that initializes User1 with a name
     * @param name The name of the user
     */
    User1(std::string name);
    
    /**
     * @brief Receive a message from a chat room
     * @param message The message content received
     * @param fromUser Pointer to the user who sent the message
     * @param room Pointer to the chat room where the message was sent
     */
    virtual void receive(std::string message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Destructor
     */
    virtual ~User1() {};
};

#endif