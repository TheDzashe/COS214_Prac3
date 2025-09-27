/**
 * @file Command.h
 * @brief Abstract command class for the Command design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class ChatRoom;
class Users;

/**
 * @class Command
 * @brief Abstract base class for all command objects in the Command design pattern
 * 
 * This class defines the interface for executing operations in the PetSpace platform.
 * Concrete command classes encapsulate specific actions like sending messages or logging activities, allowing for flexible command queuing and execution.
 */
class Command{
protected:
    ChatRoom* room;      ///< The chat room where the command will be executed
    std::string message; ///< The message content associated with the command
    Users* fromUser;     ///< The user who initiated the command

public:
    /**
     * @brief Execute the command (pure virtual)
     * 
     * This method must be implemented by concrete command classes to perform
     * the specific action associated with the command.
     */
    virtual void execute()=0;
    
    /**
     * @brief Parameterized constructor
     * @param rm Pointer to the chat room where the command will execute
     * @param msg The message content for the command
     * @param fromU Pointer to the user who initiated the command
     */
    Command(ChatRoom* rm, std::string msg, Users* fromU){
        room = rm;
        message = msg;
        fromUser = fromU;
    };
    
    /**
     * @brief Default constructor
     */
    Command();
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Command(){};
};

#endif