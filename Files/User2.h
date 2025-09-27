/**
 * @file User2.h
 * @brief Concrete colleague class representing User2 in the mediator design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef USER2_H
#define USER2_H

#include <vector>
#include <string>
#include "Users.h"

class Command;

//concrete colleague
/**
 * @class User2
 * @brief Concrete colleague implementation representing a specific user in PetSpace
 * 
 * This class represents one of the concrete users in the system that can participate in chat rooms and send/receive messages through the mediator.
 */
class User2: public Users{
public:
    //User2(ChatRoom* chatRooms, std::string name);
    /**
     * @brief Constructor that initializes User2 with a name
     * @param name The name of the user
     */
    User2(std::string name);
    
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
    virtual ~User2() {};
};

#endif