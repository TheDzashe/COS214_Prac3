/**
 * @file User3.h
 * @brief Concrete colleague class representing User3 in the mediator design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef USER3_H
#define USER3_H

#include <vector>
#include <string>
#include "Users.h"

class Command;

//concrete colleague
/**
 * @class User3
 * @brief Concrete colleague implementation representing a specific user in PetSpace
 * 
 * This class represents one of the concrete users in the system that can participate in chat rooms and send/receive messages through the mediator.
 */
class User3: public Users{
public:
    //User3(ChatRoom* chatRooms, std::string name);
    /**
     * @brief Constructor that initializes User3 with a name
     * @param name The name of the user
     */
    User3(std::string name);
    
    //virtual void send(std::string message, ChatRoom* room);
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
    virtual ~User3() {};
};

#endif