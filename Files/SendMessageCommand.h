/**
 * @file SendMessageCommand.h
 * @brief Concrete command for sending messages in the Command design pattern
 * @author Nyashadzashe
 * @date 2025
 */

#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Concrete command that handles message broadcasting operations
 * 
 * This command encapsulates the action of sending a message to all users in a chat room.
 * It follows the Command pattern by separating the request (sending) from the
 * execution, allowing for flexible command queuing and execution.
 */
class SendMessageCommand: public Command{
public:
    /**
     * @brief Execute the send message command
     * 
     * This method calls the sendMessage function on the chat room receiver
     * to broadcast the message to all users in the room.
     */
    void execute();
    
    /**
     * @brief Constructor for SendMessageCommand
     * @param room Pointer to the chat room where the message will be sent
     * @param message The message content to be broadcast
     * @param fromUser Pointer to the user who sent the message
     */
    SendMessageCommand(ChatRoom* room, std::string message, Users* fromUser);
};

#endif