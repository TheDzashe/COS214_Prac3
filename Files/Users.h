/**
 * @file Users.h
 * @brief Colleague class in the mediator design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef USERS_H
#define USERS_H

#include <vector>
#include <string>
#include "Message.h"

class ChatRoom;
class Command;

/**
 * @class Users
 * @brief Abstract colleague class that represents a user in the PetSpace platform
 * 
 * This class serves as the Colleague in the Mediator design pattern and also acts as
 * the Invoker in the Command pattern. Users communicate through ChatRoom mediators
 * and execute commands for message handling.
 */
class Users{
protected:
    std::vector<ChatRoom*> chatRooms; ///< List of chat rooms the user has joined - these are my mediators
    std::string name;                 ///< The user's name
    std::vector<Command*> commandQueue; ///< Queue of commands to be executed
    std::vector<Message*> sentMessages; ///< History of messages sent by this user - part of state design pattern, just for the print outs and stuff

public:
    /**
     * @brief Constructor that initializes the user with a name
     * @param n The name of the user
     */
    Users(std::string n){
        name = n;
    }
    
    /**
     * @brief Send a message to a chat room
     * @param message The message content to send
     * @param room Pointer to the chat room where the message will be sent
     */
    virtual void send(std::string message, ChatRoom* room);
    
    /**
     * @brief Receive a message from a chat room (pure virtual)
     * @param message The message content received
     * @param fromUser Pointer to the user who sent the message
     * @param room Pointer to the chat room where the message was sent
     */
    virtual void receive(std::string message, Users* fromUser, ChatRoom* room)=0;

    /**
     * @brief Add a command to the command queue
     * @param command Pointer to the command to be added
     */
    void addCommand(Command* command);
    
    /**
     * @brief Execute all commands in the command queue
     */
    void executeAll();
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Users();

    /**
     * @brief Get the user's name
     * @return std::string The name of the user
     */
    std::string getName();
    
    /**
     * @brief Join a chat room
     * @param chatRoom Pointer to the chat room to join
     */
    void joinChatRoom(ChatRoom* chatRoom);

    //void displayAllMessageStates();
};

#endif